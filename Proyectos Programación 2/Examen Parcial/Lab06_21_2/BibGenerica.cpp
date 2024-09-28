/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstdlib>
#include "BibGenerica.h"
#include "FunConEnteros.h"
#include "FunConRegistro.h"
using namespace std;

enum Cola{INI,FIN1,FIN2,FIN3,FIN};
enum Nodo{DATO,SGTE};

void creacola(void *&cola,void *(*lee)(ifstream &),int (*prioridad)(void*),const char *nombArch){
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
        encolar(cola,dato,prioridad);
    }
}

void inicializarCola(void *&cola){
    void **aux=new void*[5]{};
    cola=aux;
}

/*FIN3 es siempre FIN*/
void encolar(void *&cl,void *dato,int (*prior)(void*)){
    void **cola=(void**)cl;
    void **nuevoNodo,**auxFin;
    int prioridad=prior(dato);
    crearNodo(nuevoNodo,dato);
    if(esColaVacia(cl)){
        cola[INI]=nuevoNodo;
        cola[FIN]=nuevoNodo;
        if(prioridad==1) cola[FIN1]=nuevoNodo;
        else if(prioridad==2) cola[FIN2]=nuevoNodo;
        else cola[FIN3]=nuevoNodo;
    }
    else{
        if(prioridad==1){
            if(cola[FIN1]==nullptr){
                nuevoNodo[SGTE]=cola[INI];
                cola[INI]=nuevoNodo;
                cola[FIN1]=nuevoNodo;
            }
            else{
                auxFin=(void**)cola[FIN1];
                if(auxFin[SGTE]==nullptr) cola[FIN]=nuevoNodo;
                nuevoNodo[SGTE]=auxFin[SGTE];
                auxFin[SGTE]=nuevoNodo;
                cola[FIN1]=nuevoNodo;
            }
        }
        else if(prioridad==2){
            if(cola[FIN2]==nullptr){
                if(cola[FIN1]==nullptr){
                    nuevoNodo[SGTE]=cola[INI];
                    cola[INI]=nuevoNodo;
                    cola[FIN2]=nuevoNodo;
                }
                else{
                    auxFin=(void**)cola[FIN1];
                    nuevoNodo[SGTE]=auxFin[SGTE];
                    auxFin[SGTE]=nuevoNodo;
                    cola[FIN2]=nuevoNodo;
                }
            }
            else{
                auxFin=(void**)cola[FIN2];
                if(auxFin[SGTE]==nullptr) cola[FIN]=nuevoNodo;
                nuevoNodo[SGTE]=auxFin[SGTE];
                auxFin[SGTE]=nuevoNodo;
                cola[FIN2]=nuevoNodo;
            }
        }
        else{
            auxFin=(void**)cola[FIN];
            nuevoNodo[SGTE]=auxFin[SGTE];
            auxFin[SGTE]=nuevoNodo;
            cola[FIN]=nuevoNodo;
            cola[FIN3]=cola[FIN];
        }
    }
}

void *desencolar(void *cl){
    if(esColaVacia(cl)) return nullptr;
    void **cola=(void**)cl;
    void **ini=(void**)cola[INI];
    void *dato=ini[DATO];
    cola[INI]=ini[SGTE];
    delete ini;
    return dato;
}

void crearNodo(void **&nuevoNodo,void *dato){
    nuevoNodo=new void*[2]{};
    nuevoNodo[DATO]=dato;
    nuevoNodo[SGTE]=nullptr;
}

bool esColaVacia(void *cola){
    void **aux=(void**)cola;
    return aux[INI]==nullptr;
}

void descargarcola(void *cola,void (*imprime)(ofstream &,void*,int),const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int i=0;
    void **dato;
    int *num;
    void **auxCola=(void**)cola;
    dato=(void**)auxCola[FIN1];
    num=(int*)dato[DATO];
    arch<<"FIN 1: "<<*num<<endl;
    dato=(void**)auxCola[FIN2];
    num=(int*)dato[DATO];
    arch<<"FIN 2: "<<*num<<endl;
    dato=(void**)auxCola[FIN3];
    num=(int*)dato[DATO];
    arch<<"FIN 3: "<<*num<<endl;
    while(!esColaVacia(cola)){
        i++;
        imprime(arch,desencolar(cola),i);
    }
}