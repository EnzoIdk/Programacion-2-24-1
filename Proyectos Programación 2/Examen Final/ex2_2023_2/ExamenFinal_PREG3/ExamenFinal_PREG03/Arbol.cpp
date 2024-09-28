/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: margo
 * 
 * Created on 7 de julio de 2024, 13:22
 */

#include "Arbol.h"
#include <iostream>
using namespace std;
Arbol::Arbol() {
    raiz=nullptr;
}

Arbol::Arbol(const Arbol& orig) {
}

Arbol::~Arbol() {
}

void Arbol::insertarNodo(Vehiculo*&vehiculo) {
    insertarRec(vehiculo, raiz);
}

void Arbol::insertarRec(Vehiculo*&nuevo, Nodo*&raz) {
    if (raz==nullptr) {
        raz=new Nodo;
        raz->der=nullptr;
        raz->izq=nullptr;
        raz->unidad=nuevo;
        return;
    }
    if (nuevo->GetDni()<raz->unidad->GetDni()){
         insertarRec(nuevo, raz->izq);
    }else{
        insertarRec(nuevo, raz->der);
    }
}

void Arbol::reducirVehiculos(int cat) {
    int cpy=cat;
    reduccionRec(cpy, raiz);
}

void Arbol::reduccionRec(int& cat, Nodo*&nod) {
    if (nod==nullptr) return;
   
    reduccionRec(cat, nod->izq);
    reduccionRec(cat, nod->der);
   if (nod->der==nullptr and nod->izq==nullptr){
        if (cat==0){
            cout<<"ingresa a no delete"<<endl;
            return;
        }else{
            Nodo*eliminar = nod;
            nod=nullptr;
            delete eliminar;
            cat--;
            cout<<"ingresa a delete"<<endl;
            cout<<cat<<endl;
            return;
        }
    }
}

void Arbol::muestraprogramacion(ofstream& arch) {
    enOrdenRec(arch, raiz);
}

void Arbol::enOrdenRec(ofstream&arch, Nodo *&nod) {
    if (nod==nullptr){
        cout<<"el nodo es nullo"<<endl;
        return;
    }else{
        cout<<"ingresa izq"<<endl;
        enOrdenRec(arch,nod->izq);
        cout<<"el nodo no es nullo"<<endl;
       if (nod->unidad!=nullptr) nod->unidad->imprimir(arch);
        enOrdenRec(arch,nod->der);
    }
}


