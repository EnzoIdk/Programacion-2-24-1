/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Enzo
 * 
 * Created on 8 de julio de 2024, 10:30 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
}

Pedido::Pedido(const Pedido& orig) {
    *this=orig;
}

Pedido::~Pedido() {
}

void Pedido::SetPeso(double peso) {
    this->peso = peso;
}

double Pedido::GetPeso() const {
    return peso;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::operator =(const class Pedido& orig){
    SetCodigo(orig.GetCodigo());
    SetCantidad(orig.GetCantidad());
    SetPeso(orig.GetPeso());
}

bool Pedido::operator <(const class Pedido& orig){
    return peso<orig.peso;
}

void Pedido::leerDatos(ifstream& arch){
    getline(arch,codigo,',');
    arch>>cantidad;
    arch.get();
    arch>>peso;
    arch.get(); //'\n'
}

void Pedido::mostrar(ofstream& arch){
    arch<<codigo<<setw(10)<<peso<<setw(2)<<' '<<cantidad<<endl;
}

