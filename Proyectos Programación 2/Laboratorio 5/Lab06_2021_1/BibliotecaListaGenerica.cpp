/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstdlib>

using namespace std;

#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistros.h"
enum Nodo{DATO,SGTE};
enum Lista{CABEZA,COLA};

void creaLista(void *&lista,void*(*lee)(ifstream &),int (*cmp)(const void*,
        const void*),const char *nombArch){
    void *dato;
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    lista=nullptr;
    inicializarLista(lista);
    while(true){
        dato=lee(arch);
        if(arch.eof()) break;
        insertar(dato,lista,cmp);
    }
}

void inicializarLista(void *&lista){
    void **registro=new void*[2];
    registro[CABEZA]=nullptr;
    registro[COLA]=nullptr;
    lista=registro;
}

void insertar(void *dato,void *&lista,int (*cmp)(const void*,const void*)){
    void **registroLista=(void**)lista;
    void **nuevoNodo,**ptActual,**ptAnt=nullptr;
    crearNuevoNodo(nuevoNodo,dato);
    if(registroLista[CABEZA]==nullptr){ /*si no habían elementos*/
        registroLista[CABEZA]=nuevoNodo;
        registroLista[COLA]=nuevoNodo;
    }
    else{
        ptActual=(void**)registroLista[CABEZA]; /*apunta al inicio*/
        while(ptActual){ /*es decir, mientras no sea nullptr*/
            if(cmp(ptActual[DATO],dato)>0) break; /*si el dato es menor, lo insertamos allí*/
            ptAnt=ptActual;
            ptActual=(void**)ptActual[SGTE];
        }
        nuevoNodo[SGTE]=ptActual;
        if(ptAnt==nullptr) registroLista[CABEZA]=nuevoNodo;
        else{
            ptAnt[SGTE]=nuevoNodo;
            if(ptActual==nullptr) registroLista[COLA]=nuevoNodo;
        }
    }
}

void crearNuevoNodo(void **&nuevoNodo,void *dato){
    nuevoNodo=new void*[2];
    nuevoNodo[DATO]=dato;
    nuevoNodo[SGTE]=nullptr;
}

void imprimeLista(void *lst,void (*imprime)(ofstream &,void*,void*&),const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **lista=(void**)lst;
    void **ptActual=(void**)lista[CABEZA],*ptAnt=nullptr;
    arch<<setprecision(2)<<fixed;
    while(!esListaVacia(ptActual)){
        imprime(arch,ptActual[DATO],ptAnt);
        ptActual=(void**)ptActual[SGTE];
    }
}

bool esListaVacia(void *lista){
    if(lista==nullptr) return true;
    else return false;
}

void uneLista(void *&lista1,void *lista2){
    void **auxLista1=(void**)lista1,**auxLista2=(void**)lista2;
    void **ptCola1=(void**)auxLista1[COLA];
    ptCola1[SGTE]=auxLista2[CABEZA];
    auxLista1[COLA]=auxLista2[COLA];
}