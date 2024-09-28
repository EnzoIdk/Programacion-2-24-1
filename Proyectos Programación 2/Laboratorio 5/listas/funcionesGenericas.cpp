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
enum Lista{
    INICIO, FIN
};
void construit(void *&lista,void *(*leeEntero)(ifstream &arch), ifstream &arch, void (*construirLista)(void*, void*&) ){
    void *dato;
    lista=nullptr;
    while(true){
        dato=leeEntero(arch);
        if (arch.eof()) break;
        construirLista(dato, lista);
    }
}
void imprimir(void *lista, void (*imprimEntero)(ofstream &arch, void*), ofstream &arch){
    //si es con enteros
//     void **p=lista
     //si es con una pila o cola
    void **cabeza=(void**)lista;
    void **p=(void**)cabeza[INICIO];
    while(p){
        imprimEntero(arch, p[VALOR]);
        p=(void**)p[SIGUIENTE];
    }
}