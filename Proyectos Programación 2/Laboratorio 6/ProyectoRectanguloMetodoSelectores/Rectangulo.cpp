/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Rectangulo.cpp
 * Author: Enzo
 * 
 * Created on 19 de mayo de 2024, 09:33 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Rectangulo.h"

Rectangulo::Rectangulo() {
    cout<<"Constructor Defecto"<<endl;
    nombre=nullptr;
}

Rectangulo::Rectangulo(const Rectangulo& orig) {
}

Rectangulo::~Rectangulo() {
}

