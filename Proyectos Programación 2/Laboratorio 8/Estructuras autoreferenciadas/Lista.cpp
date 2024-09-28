/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Lista.cpp
 * Author: aml
 * 
 * Created on 4 de junio de 2024, 08:33 AM
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
    /*se desarrollara en otro metodo*/
    elimina();
    cout<<"Se ha eliminado la lista"<<endl;
}

void Lista::crear(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int dato;
    while(true){
        arch>>dato;
        if(arch.eof()) break;
        insertar(dato);
    }
}

void Lista::insertar(int dato){
    class Nodo *rec=lista,*ant=nullptr,*nuevoNodo;
    nuevoNodo=new class Nodo;
    nuevoNodo->dato=dato;
    while(rec){ /*hasta que rec sea nulo*/
        if(rec->dato>dato) break; /*insertar ordenado*/
        ant=rec;
        rec=rec->siguiente;
    }
    nuevoNodo->siguiente=rec;
    if(ant!=nullptr) ant->siguiente=nuevoNodo;
    else lista=nuevoNodo;
}

void Lista::imprimir(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Nodo *rec=lista; /*no se trabaja directamente en el puntero lista*/
    arch<<"Datos de la lista"<<endl;
    while(rec){
        arch<<setw(10)<<rec->dato;
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
    lista=nullptr;
}

void Lista::imprimeR(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    imprimeRecursivo(arch,lista);
    arch<<endl;
}

void Lista::imprimeRecursivo(ofstream &arch,class Nodo *rec){
    if(rec==nullptr) return;
    imprimeRecursivo(arch,rec->siguiente);
    arch<<setw(10)<<rec->dato;
}