/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NPedido.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 12:19 PM
 */

#include <iomanip>
using namespace std;
#include <cstring>

#include "NPedido.h"

NPedido::NPedido() {
    codigo=nullptr;
    sig=nullptr;
}

NPedido::~NPedido() {
    if(codigo!=nullptr) delete codigo;
}


void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(char * cad) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cad)+1];
    strcpy(codigo, cad);
}

void NPedido::GetCodigo(char * cad) const {
    if(codigo==nullptr) cad[0]=0;
    else strcpy(cad, codigo);
}

void NPedido::setDatos(char* cod, int cant, double peso){
    this->SetCodigo(cod);
    this->SetCantidad(cant);
    this->SetPeso(peso);
}

void NPedido::imprime(ofstream& arch){
    arch<<setw(25)<<codigo<<setw(10)<<cantidad<<setw(10)<<peso<<endl;
}


