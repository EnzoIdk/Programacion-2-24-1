/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoEventual.cpp
 * Author: Enzo
 * 
 * Created on 7 de julio de 2024, 11:20 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PedidoEventual.h"

PedidoEventual::PedidoEventual() {
}

PedidoEventual::PedidoEventual(const PedidoEventual& orig) {
}

PedidoEventual::~PedidoEventual() {
}

void PedidoEventual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoEventual::GetFlete() const {
    return flete;
}

void PedidoEventual::lee(int cod,ifstream &arch){
    arch.get();
    arch>>flete;
    Pedido::lee(cod,arch);
}

void PedidoEventual::actualiza(){
    flete=0;
}

void PedidoEventual::imprime(ofstream& arch, double a, double b){
    Pedido::imprime(arch,0,flete);
    arch<<"Flete: "<<flete<<endl;
}

