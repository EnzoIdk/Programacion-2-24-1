/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
enum Nodo{
    VALOR, SIGUIENTE
};
enum Cola{
    INICIO, FIN, LONG
};
void  construirCola(void *dato, void *&cola){
    void**nuevo=new void*[2]{};
    nuevo[VALOR]=dato;
    if (cola==nullptr){//si la cola está vacía
        void **cabeza=new void*[3]{};
        cabeza[INICIO] = nuevo;
        cabeza[FIN] = nuevo;
        int *longi=new int;
        *longi=1;
        cabeza[LONG]=longi;
        cola=cabeza;
    }else{
        void **cabeza=(void**)cola;
        void**ultimo=(void**)cabeza[FIN];
        ultimo[SIGUIENTE]=nuevo;
        cabeza[FIN]=nuevo;
        int *longi=(int*)cabeza[LONG];
        (*longi)++;
    }
}
int cmpCola(const void*a, const void*b){
    void **nodoA=(void**)a;
    void **nodoB=(void**)b;
    int *valorA=(int*)nodoA[VALOR];
    int *valorB=(int*)nodoB[VALOR];
    return *valorA-*valorB;
}