/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and ope
 * n the template in the editor.
 */

/* 
 * File:   Literatura.cpp
 * Author: margo
 * 
 * Created on 29 de mayo de 2024, 9:22
 */

#include "Literatura.h"
#include "Libro.h"
#include <cstring>
using namespace std;
Literatura::Literatura() {
    descuento=0;
}

Literatura::Literatura(const Literatura& orig) {
}

Literatura::~Literatura() {
}

void Literatura::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Literatura::GetDescuento() const {
    return descuento;
}

void Literatura::lectura(ifstream&arch) {
    //LIT L003, Rayuela, 1, 3 19
    Libro::lectura(arch);
    arch>>descuento;
    arch.get();
}
