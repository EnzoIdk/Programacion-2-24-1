/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Arbol.cpp
 * Author: Lucas
 * 
 * Created on 7 de julio de 2024, 07:19 PM
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "Arbol.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

Arbol::Arbol() {
    raiz=nullptr;
}

Arbol::Arbol(const class Arbol &orig) {

}

Arbol::~Arbol() {
    this->eliminar();
}

//GETTERS Y SETTERS

//METODOS
void Arbol::insertar(class Vehiculo * vehiculo){
    this->insertarRec(raiz, vehiculo);
}

void Arbol::insertarRec(class Nodo * &parbol, class Vehiculo * vehiculo){
    //SI ES ARBOL VACIO
    if(parbol==nullptr){
        parbol=new class Nodo;
        parbol->unidad=vehiculo;
        return;
    }
    //RECURSIVIDAD
    if(parbol->unidad->GetPlaca()>vehiculo->GetPlaca()){
        if(parbol->izq!=nullptr) this->insertarRec(parbol->izq, vehiculo);
        else{
            parbol->izq=new class Nodo;
            parbol->izq->unidad=vehiculo;
        }
    }
    else{
        if(parbol->der!=nullptr) this->insertarRec(parbol->der, vehiculo);
        else{
            parbol->der=new class Nodo;
            parbol->der->unidad=vehiculo;
        }
    }
}

void Arbol::recorrerEnOrden(ofstream &arch){
    this->recorrerEnOrdenRec(raiz, arch);
}

void Arbol::recorrerEnOrdenRec(class Nodo * parbol, ofstream &arch){
    if(parbol!=nullptr){
        recorrerEnOrdenRec(parbol->izq, arch);
        parbol->unidad->mostrar(arch);
        recorrerEnOrdenRec(parbol->der, arch);
    }
}

void Arbol::eliminarNodo(int cantidad){
    this->eliminarNodoRec(raiz, cantidad);
}

void Arbol::eliminarNodoRec(class Nodo * &parbol, int &cantidad){
    if(parbol!=nullptr){
        eliminarNodoRec(parbol->izq, cantidad);
        eliminarNodoRec(parbol->der, cantidad);
        if(cantidad>0 and parbol->izq==nullptr and parbol->der==nullptr){
            delete parbol;
            parbol=nullptr;
            cantidad--;
        }
    }
}

void Arbol::eliminar(){
    this->eliminarRec(raiz);
    raiz=nullptr;
}

void Arbol::eliminarRec(class Nodo * parbol){
    if(parbol!=nullptr){
        eliminarRec(parbol->izq);
        eliminarRec(parbol->der);
        delete parbol;
    }
}
//FUNCIONES
