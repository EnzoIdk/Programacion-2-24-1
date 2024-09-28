/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "ColaGenerica.h"
enum cabe{
    INI, FIN, TOTAL
};
enum nodo{
    VALOR, SIGU
};
void encolar(void *&cola, void*reg){
    void **nuevo=new void*[2]{};
    nuevo[VALOR]=reg;
    void **cabeza=(void**)cola;
    if (cabeza[INI]==nullptr ){
        cabeza[INI]=nuevo;
        cabeza[FIN]=nuevo;
    }else{
        void **ultimo=(void**)cabeza[FIN];
        ultimo[SIGU]=nuevo;
        cabeza[FIN]=nuevo;
    }
}
void crearCola(void *&cola){
    void **cabeza=new void*[3]{};
    int elementos=0, *ele=new int;
    cabeza[INI]=nullptr;
    cabeza[FIN]=nullptr;
    *ele=0;
    cabeza[TOTAL]=ele;
    cola=cabeza;
}
bool colavacia(void*&cola){
   void **cabeza=(void**)cola;
    if (cabeza[INI]==nullptr){
        return true;
    }else{
        return false;
    }
}
void* desencolar(void *&cola){
    void **cabeza=(void**)cola;
    void**primero=(void**)cabeza[INI];
    void**eliminar=(void**)cabeza[INI];
    cabeza[INI]=(void**)primero[SIGU];
    eliminar[SIGU]=nullptr;
    return eliminar[VALOR];
}