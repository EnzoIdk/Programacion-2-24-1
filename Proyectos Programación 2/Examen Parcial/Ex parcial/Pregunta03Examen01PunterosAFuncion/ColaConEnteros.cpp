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
#include "ColaConEnteros.h"
enum nodo{
    VALOR, SIGU
};
enum cabe{
    INI, FIN, TOTAL
};
void   cargaEnteros(void *&cola, void* (*leenumero)(ifstream &arch),const char *nombarch){
    ifstream arch(nombarch, ios::in);
    if (not arch.is_open()){
        cout<<"error con la apertura: "<<nombarch<<endl;
        exit(1);
    }
    void *reg;
    cola=nullptr;
     crearCola(cola);
     int contador=0;
    while(true){
        reg=leenumero(arch);
        if (arch.eof()) break;
        encolar(cola, reg);
        contador+=*(int*)reg;
    }
     int *cont=new int;
     *cont=contador;
     void**cabeza=(void**)cola;
     cabeza[TOTAL]=cont;
}
void *leenumero(ifstream &arch){
    int numero, *num=new int;
    arch>>numero;
    *num=numero;
    return num;
}
void  mostrarEnteros(void *&cola, void(*imprimeNumero)(void*,ofstream &arch), const char*nombarch){
    ofstream arch(nombarch, ios::out);
    if (not arch.is_open()){
        cout<<"error con la apertura: "<<nombarch<<endl;
        exit(1);
    }
    void **cabe=(void**)cola;
    while(!colavacia(cola)){
        void *numero=desencolar(cola);
        imprimeNumero(numero, arch);
        void **eliminar=(void**)numero;
        delete eliminar;
    }
    arch<<"TOTAL:"<<*(int*)cabe[TOTAL]<<endl;
    
}
void imprimeNumero(void*recorrido, ofstream &arch){
    int *numero=(int*)recorrido;
    arch<<*numero<<endl;
}

