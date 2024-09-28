/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: margo
 * 
 * Created on 7 de julio de 2024, 13:21
 */

#include "Nodo.h"

Nodo::Nodo() {
    der=nullptr;
    izq=nullptr;
    unidad=nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
    if (unidad!=nullptr) delete unidad;
}

