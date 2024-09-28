/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 12:46 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Producto.h"

Producto::Producto() {
    nombre=nullptr;
    
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
    if(nombre!=nullptr) delete nombre;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetNombre(const char *cad) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Producto::GetNombre(char *cad) const {
    if(nombre==nullptr) cad[0]=0;
    else strcpy(cad,nombre);
}

void Producto::SetCodProd(int codProd) {
    this->codProd = codProd;
}

int Producto::GetCodProd() const {
    return codProd;
}

void Producto::leeProd(ifstream& arch){
    arch>>codProd;
    if(arch.eof()) return;
    arch.get();
    char aux[60];
    arch.getline(aux,60,',');
    SetNombre(aux);
    arch>>stock;
    arch.get();
}

void Producto::imprimeProd(ofstream& arch){
    arch<<setw(10)<<codProd<<setw(50)<<nombre<<setw(10)<<stock<<endl;
}