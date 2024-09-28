/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Enzo
 * 
 * Created on 7 de julio de 2024, 10:06 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
    nombre=nullptr;
    total=0;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
    if(nombre!=nullptr) delete nombre;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetNombre(const char *cad) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Pedido::GetNombre(char *cad) const {
    if(nombre==nullptr) cad[0]=0;
    else strcpy(cad,nombre);
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::lee(int cod, ifstream& arch){
    char cad[60],car;
    int dd,mm,aa;
    arch.get();
    SetCodigo(cod);
    arch.getline(cad,60,',');
    SetNombre(cad);
    arch>>cantidad;
    arch.get();
    arch>>total;
    arch.get();
    arch>>dni;
    arch.get();
    arch>>dd>>car>>mm>>car>>aa;
    arch.get();
    SetFecha(aa*10000+mm*100+dd);
}

void Pedido::imprime(ofstream &arch,double desc,double fle){
    char cad[60];
    double monto;
    arch<<endl<<left <<setw(10)<<GetFecha()<<endl;
    GetNombre(cad);
    arch <<setw(10)<<codigo<<setw(50)<< cad <<endl;
    arch<<"DNI: "<< dni << endl;
    arch <<"Monto Total: "<<right<<setprecision(2)<<fixed;
    monto = GetTotal()+(GetTotal()*fle/100)-(GetTotal()*desc/100);
    arch <<setw(10)<< monto <<endl;
}