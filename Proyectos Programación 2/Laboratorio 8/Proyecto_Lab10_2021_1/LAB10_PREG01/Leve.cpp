/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Leve.cpp
 * Author: ISA
 * 
 * Created on 6 de junio de 2024, 03:56 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Leve.h"

Leve::Leve() {
    descuento = 0.0;
}

Leve::Leve(const Leve& orig) {
}

Leve::~Leve() {
}
void Leve::operator=(const Leve& orig){
    Infraccion::operator =(orig);
    descuento = orig.descuento;
}
void Leve::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Leve::GetDescuento() const {
    return descuento;
}

bool Leve::lee(ifstream &arch, int cod){
    bool encontrado = Infraccion::lee(arch,cod);
    if(encontrado){
        arch >> descuento;
        arch.get();
    }
    return encontrado;
}

void Leve::imprime(ofstream &arch){
    arch << setw(10) << descuento << setw(10) << 0 << setw(10) << 0 << endl;
}