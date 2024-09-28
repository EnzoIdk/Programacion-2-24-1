/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoEspecial.cpp
 * Author: Enzo
 * 
 * Created on 7 de julio de 2024, 11:21 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PedidoEspecial.h"

PedidoEspecial::PedidoEspecial() {
    descuento=0;
}

PedidoEspecial::PedidoEspecial(const PedidoEspecial& orig) {
}

PedidoEspecial::~PedidoEspecial() {
}

void PedidoEspecial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoEspecial::GetDescuento() const {
    return descuento;
}

void PedidoEspecial::lee(int cod, ifstream& arch){
    arch.get();
    arch>>descuento;
    Pedido::lee(cod,arch);
}

void PedidoEspecial::imprime(ofstream& arch, double, double){
    Pedido::imprime(arch,descuento,0);
    arch<<"Descuento: "<<descuento<<endl;
}

void PedidoEspecial::actualiza(){
    
}