/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   NPedido.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 12:10
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "NPedido.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

NPedido::NPedido() {
    codigo=nullptr;
}

NPedido::NPedido(const class NPedido &orig) {
    codigo=nullptr;
    *this=orig;
}

NPedido::~NPedido() {
    if(codigo!=nullptr) delete codigo;
}

//GETTERS Y SETTERS
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

void NPedido::SetCodigo(char* cad) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cad)+1];
    strcpy(codigo, cad);
}

void NPedido::GetCodigo(char * cad) const {
    if(codigo==nullptr) cad[0]=0;
    else strcpy(cad, codigo);
}

//METODOS
void NPedido::operator =(const class NPedido& orig){
    char codTemp[10];
    orig.GetCodigo(codTemp);
    //
    this->SetPeso(orig.GetPeso());
    this->SetCantidad(orig.GetCantidad());
    this->SetCodigo(codTemp);
}

void NPedido::imprimir(ofstream& arch){
    char codPed[10];
    this->GetCodigo(codPed);
    //
    arch<<setw(10)<<codPed<<setw(8)<<this->GetCantidad()<<setw(10)<<
            this->GetPeso()<<endl;
}

//FUNCIONES
