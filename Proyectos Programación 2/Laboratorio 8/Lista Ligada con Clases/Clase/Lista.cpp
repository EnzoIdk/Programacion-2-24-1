/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: Enzo
 * 
 * Created on 9 de junio de 2024, 09:33 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Lista.h"

Lista::Lista() {
    lista=nullptr;
}

Lista::~Lista() {
    elimina();
}

void Lista::crear(const char* nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Persona dato;
    while(true){
        arch>>dato; //sobrecargado
        if(arch.eof()) break;
        insertar(dato);
    }
}

void Lista::insertar(const class Persona& dato){
    class Nodo *rec=lista,*ant=nullptr;
    class Nodo *nuevoNodo=new class Nodo;
    nuevoNodo->dato=dato; //sobrecargado
    while(rec){
        if(rec->dato>dato) break; //sobrecargado
        ant=rec;
        rec=rec->siguiente;
    }
    nuevoNodo->siguiente=rec;
    if(ant!=nullptr) ant->siguiente=nuevoNodo;
    else lista=nuevoNodo;
}

void Lista::imprimir(const char* nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Nodo *rec=lista;
    arch<<"Datos de la lista"<<endl;
    while(rec){
        arch<<rec->dato; //sobrecargado
        rec=rec->siguiente;
    }
    arch<<endl;
}

void Lista::elimina(){
    class Nodo *sale;
    while(lista){
        sale=lista;
        lista=lista->siguiente;
        delete sale;
    }
    lista=nullptr; //por si se trabaja con una nueva lista luego
}

void Lista::imprimeR(const char* nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<"Datos de la lista"<<endl;
    imprimeRecursivo(arch,lista);
    arch<<endl;
}

void Lista::imprimeRecursivo(ofstream& arch, Nodo* p){
    if(p==nullptr) return;
    imprimeRecursivo(arch,p->siguiente);
    arch<<p->dato;
}
