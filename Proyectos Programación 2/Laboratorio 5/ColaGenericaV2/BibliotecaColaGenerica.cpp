/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "BibliotecaColaGenerica.h"
#include "ColaConEnteros.h"

enum Nodo{DATO,SGTE};
enum Cola{INI,FIN};

void crearCola(const char *nombArch,void *&cola,void*(*lee)(ifstream &)){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *dato;
    construirCola(cola);
    while(true){
        dato=lee(arch);
        if(arch.eof()) break;
        encolar(cola,dato);
    }
}

void construirCola(void *&cola){
    cola=nullptr;
    inicializarCola(cola);
}

void inicializarCola(void *&cola){
    void **aux=new void*[2];
    aux[INI]=nullptr;
    aux[FIN]=nullptr;
    cola=aux;
}

void encolar(void *&cola,void *dato){
    void **regCola=(void**)cola;
    void **fin,**nuevoNodo;
    crearNuevoNodo(nuevoNodo,dato);
    if(esColaVacia(cola)){
        regCola[INI]=nuevoNodo;
        regCola[FIN]=nuevoNodo;
    }
    else{
        fin=(void**)regCola[FIN];
        fin[SGTE]=nuevoNodo;
        regCola[FIN]=nuevoNodo;
    }
}

void * desencolar (void *&Cola) {
    void **p_ptr = (void **)Cola;
    void **sale;
    void **devuelve;
    void **p = (void **)p_ptr[INI];   
    if (esColaVacia(Cola)) return nullptr;
    sale = (void **)p_ptr[INI];
    p_ptr[INI] = p[SGTE];
    if (p_ptr[INI] == nullptr) p_ptr[FIN] = p[SGTE];
    devuelve = (void **)sale[DATO]; 
    delete sale;
    return devuelve;
}

void crearNuevoNodo(void **&nuevoNodo,void *dato){
    nuevoNodo=new void*[2];
    nuevoNodo[DATO]=dato;
    nuevoNodo[SGTE]=nullptr;
}

bool esColaVacia(void *cola){
    void **regCola=(void**)cola;
    return !regCola[INI] and !regCola[FIN];
}

void imprimirCola(void *cola,void (*imprime)(ofstream &,void*),const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    while(!esColaVacia(cola)){
        imprime(arch,desencolar(cola));
    }
}