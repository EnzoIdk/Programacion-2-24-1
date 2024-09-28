/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: margo
 * 
 * Created on 7 de julio de 2024, 6:49
 */

#include "Pedido.h"
#include <fstream>
#include <iostream>
using namespace std;
Pedido::Pedido() {
    cout<<"constructor  pedido"<<endl;
}

Pedido::Pedido(const Pedido& orig) {
    cout<<"constructor copia pedido"<<endl;
    this->codigo=orig.GetCodigo();
  //   cout<"codigo: "<<codigo<<endl;
    this->cantidad = orig.GetCantidad();
    this->peso = orig.GetPeso();
}

Pedido::~Pedido() {
     cout<<"codigo: "<<codigo<<endl;
    //cout<<"destructor copia pedido"<<endl;
    cout<<"fin de destructor"<<endl;
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

void Pedido::lee(ifstream &arch) {
    getline(arch, codigo, ',');
    arch>>cantidad;
    arch.get();
    arch>>peso;
    arch.get();
}

void Pedido::imprime(ofstream&arch) {
    arch<<codigo<<' '<<cantidad<<' '<<peso<<endl;
}

