/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Nodo.cpp
 * Author: Enzo
 * 
 * Created on 8 de julio de 2024, 03:06 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Nodo.h"

Nodo::Nodo() {
    unidad=nullptr;
    sig=nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
//    if(unidad!=nullptr) delete unidad;
}

