/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: Usuario
 * 
 * Created on 5 de junio de 2024, 01:21 PM
 */

#include "Nodo.h"

Nodo::Nodo() {
    dato=nullptr;
    siguiente=nullptr;
}

Nodo::Nodo(void *&dato) {
    this->dato=dato;
    siguiente=nullptr;
}

Nodo::~Nodo() {
//    cout<<"Nodo: 'Me destuyo'"<<endl;
}

