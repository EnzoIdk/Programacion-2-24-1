/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
enum pila{
    VALOR, SIGUIENTE
};
enum camion{
    PILA, MAX
};
void *leenumero(ifstream &arch){
    int num, *ptr=new int;
    arch>>num;
    if (arch.eof()) return nullptr;
    *ptr=num;
    return ptr;
}
void  imprimenumero(ofstream &arch,void*camion){
//    void**pila=(void**)camion;
    if (camion!=nullptr) arch<<*(int*)camion<<endl;
}
int calculanumero(void *numero){
    int *num=(int*)numero;
    return *num;
}
int cmpnumero(const void*a, const void*b){
    void **ai=(void**)a;
    void **bi=(void**)b;
    void **regA=(void**)(*ai);
    void **regB=(void**)(*bi);
    int  *valorA=(int*)regA[MAX];
    int  *valorB=(int*)regB[MAX];
    return *valorB-*valorA;
}