/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductoEntregado.cpp
 * Author: alulab14
 * 
 * Created on 22 de mayo de 2024, 10:35 AM
 */

#include <iomanip>
#include <iostream>
#include <cstring>

using namespace std;

#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado() {
    codigo=nullptr;
    precio=0;
}

ProductoEntregado::ProductoEntregado(const char *cod,double p) {
    codigo=nullptr;
    precio=p;
    SetCodigo(cod);
}

ProductoEntregado::~ProductoEntregado() {
    if(codigo!=nullptr){
        delete codigo;
    }
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(const char *cod) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cod)+1];
    strcpy(codigo,cod);
}

void ProductoEntregado::GetCodigo(char *cod) const {
    if(codigo==nullptr) cod[0]=0;
    else strcpy(cod,codigo);
}

