/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "BibliotecaListaGenerica.h"

enum Nodo{DATO,SIG};

void crearLista(const char *nombArch,void *&lista,void* (*lee)(ifstream &),
        int (*cmp)(const void*,const void*)){
    void *dato;
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    lista=nullptr;
    while(true){
        dato=lee(arch);
        if(arch.eof()) break;
        insertar(dato,lista,cmp);
    }
}

/*insertando en orden*/
void insertar(void *dato,void *&lista,int(*cmp)(const void*,const void*)){
    void **p=(void**)lista,**ant=nullptr,**nuevo;
    /*nuevo nodo*/
    nuevo=new void*[2];
    nuevo[DATO]=dato;
    /*esta iterativa es la que ordena*/
    while(p){
        if(cmp(p[DATO],dato)>0) break;
        ant=p;
        p=(void**)(p[SIG]);
    }
    nuevo[SIG]=p;
    if(ant==nullptr) lista=nuevo; /*quiere decir que no se movió, el nodo se inserta al inicio*/
    else ant[SIG]=nuevo;
}

void imprimirLista(void *lst,void (*imprime)(void*)){
    void **lista=(void**)lst;
    while(lista){
        imprime(lista[DATO]);
        lista=(void**)(lista[SIG]);
    }
    cout<<endl;
}

void eliminarLista(void *lst,void  (*elimina)(void*)){
    void **lista=(void**)lst,**sale;
    while(lista){
        sale=lista;
        elimina(lista[DATO]);
        lista=(void**)(lista[SIG]);
        delete sale;
    }
}