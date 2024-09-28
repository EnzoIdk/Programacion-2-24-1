/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoUsual.cpp
 * Author: Enzo
 * 
 * Created on 7 de julio de 2024, 11:20 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PedidoUsual.h"

PedidoUsual::PedidoUsual() {
}

PedidoUsual::PedidoUsual(const PedidoUsual& orig) {
}

PedidoUsual::~PedidoUsual() {
}

void PedidoUsual::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoUsual::GetDescuento() const {
    return descuento;
}

void PedidoUsual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoUsual::GetFlete() const {
    return flete;
}

void PedidoUsual::lee(int cod, ifstream &arch){
    arch.get();
    arch>>descuento;
    arch.get();
    arch>>flete;
    Pedido::lee(cod,arch);
}

void PedidoUsual::actualiza(){
    flete=0;
}

void PedidoUsual::imprime(ofstream &arch, double a, double b){
    Pedido::imprime(arch,descuento,flete);
    arch<<"Descuento: "<<descuento<<endl;
    arch<<"Flete: "<<flete<<endl;
}