/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NodoLista.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 12:45 PM
 */

#include "NodoLista.h"

NodoLista::NodoLista() {
    unidad=nullptr;
    sig=nullptr;
}

NodoLista::~NodoLista() {
    if(unidad!=nullptr) delete unidad;
}

