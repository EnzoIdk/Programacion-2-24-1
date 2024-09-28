/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Nodo.cpp
 * Author: Lucas
 * 
 * Created on 7 de julio de 2024, 07:10 PM
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "Nodo.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

Nodo::Nodo() {
    unidad=nullptr;
    izq=nullptr;
    der=nullptr;
}

Nodo::Nodo(const class Nodo &orig) {

}

Nodo::~Nodo() {
    delete unidad;
}

//GETTERS Y SETTERS


//METODOS


//FUNCIONES
