/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "PriorityQueu.h"

enum Cola{INI,FIN};
enum Nodo{DATO,ANT,SGTE};

void crearCola(void *&cola,void *(*lee)(ifstream &),int (*obtenerPrioridad)(void*),const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    inicializarCola(cola);
    void *dato;
    while(true){
        dato=lee(arch);
        if(arch.eof()) break;
        encolar(cola,dato,obtenerPrioridad);
    }
}

void inicializarCola(void *&cola){
    void **aux=new void*[2]{};
    aux[INI]=nullptr;
    aux[FIN]=nullptr;
    cola=aux;
}

void encolar(void *&cola,void *dato,int (*obtenerPrioridad)(void*)){
    int p1,p2;
    void **auxCola=(void**)cola,**nuevoNodo;
    void **ptActual,**ptAnt=nullptr;
    crearNodo(nuevoNodo,dato);
    if(esColaVacia(cola)){
        auxCola[INI]=nuevoNodo;
        auxCola[FIN]=nuevoNodo;
    }
    else{
        ptActual=(void**)auxCola[FIN];
        p1=obtenerPrioridad(dato);
        while(ptActual){
            p2=obtenerPrioridad(ptActual[DATO]);
            if(p1<=p2){
                agregar(ptActual,nuevoNodo,obtenerPrioridad,ptAnt,auxCola,p2);
                return;
            }
            else{
                ptAnt=ptActual;
                ptActual=(void**)ptActual[ANT];
            }
        }
        nuevoNodo[SGTE]=ptAnt;
        ptAnt[ANT]=nuevoNodo;
        auxCola[DATO]=nuevoNodo;
    }
}

void agregar(void **ptActual,void **nuevoNodo,int (*obtenerPrioridad)(void*),
        void **ptAnt,void **cola,int p2){
    void **finCola=(void**)cola[FIN];
    ptActual[SGTE]=nuevoNodo;
    nuevoNodo[ANT]=ptActual;
    /*si se agrega al final*/
    if(p2==obtenerPrioridad(finCola[DATO])) cola[FIN]=nuevoNodo;
    else{
        nuevoNodo[SGTE]=ptAnt;
        ptAnt[ANT]=nuevoNodo;
    }
}

void *desencolar(void *cola){
    if(esColaVacia(cola)) return nullptr;
    void **auxCola=(void**)cola;
    void **ini=(void**)auxCola[INI];
    void **penultimo,*dato;
    /*antes de desencolar, se debe ajustar la nueva cola*/
    if(auxCola[INI]==auxCola[FIN]){ /*solo un elemento*/
        auxCola[INI]=nullptr;
        auxCola[FIN]=nullptr;
    }
    else{ /*para más elementos, el anterior también se debe variar*/
        penultimo=(void**)ini[SGTE];
        auxCola[INI]=penultimo;
        penultimo[ANT]=nullptr;
    }
    dato=ini[DATO];
    delete ini;
    return dato;
}

void crearNodo(void **&nodo,void *dato){
    nodo=new void*[3]{};
    nodo[DATO]=dato;
    nodo[ANT]=nullptr;
    nodo[SGTE]=nullptr;
}

bool esColaVacia(void *cola){
    void **aux=(void**)cola;
    return aux[INI]==nullptr;
}

void prueba(void *cola,void (*imprime)(ofstream &,void*),const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    while(!esColaVacia(cola)){
        imprime(arch,desencolar(cola));
    }
}