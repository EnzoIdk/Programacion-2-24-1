/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Nodo.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 18:53
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "Nodo.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

Nodo::Nodo() {
    plibro=nullptr;
    sig=nullptr;
}

Nodo::Nodo(const class Nodo &orig) {

}

Nodo::~Nodo() {
    if(plibro!=nullptr) delete plibro;
}

//GETTERS Y SETTERS


//METODOS


//FUNCIONES
