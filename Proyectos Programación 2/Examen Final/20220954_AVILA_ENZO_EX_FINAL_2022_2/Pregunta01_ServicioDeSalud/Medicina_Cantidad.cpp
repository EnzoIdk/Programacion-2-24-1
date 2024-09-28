/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Medicina_Cantidad.cpp
 * Author: Enzo
 * 
 * Created on 8 de julio de 2024, 07:26 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Medicina_Cantidad.h"

Medicina_Cantidad::Medicina_Cantidad() {
}

Medicina_Cantidad::Medicina_Cantidad(const Medicina_Cantidad& orig) {
    cantidad=orig.cantidad;
    codigo=orig.codigo;
}

Medicina_Cantidad::~Medicina_Cantidad() {
}

void Medicina_Cantidad::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Medicina_Cantidad::GetCantidad() const {
    return cantidad;
}

void Medicina_Cantidad::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Medicina_Cantidad::GetCodigo() const {
    return codigo;
}

void operator >>(ifstream &arch,class Medicina_Cantidad &dato){
    int codigo,cantidad;
    arch>>codigo;
    arch.get();
    arch>>cantidad;
    dato.SetCodigo(codigo);
    dato.SetCantidad(cantidad);
}