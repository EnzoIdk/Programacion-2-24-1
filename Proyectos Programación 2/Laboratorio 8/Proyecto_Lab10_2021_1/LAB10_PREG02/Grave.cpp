/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grave.cpp
 * Author: ISA
 * 
 * Created on 6 de junio de 2024, 03:57 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Grave.h"

Grave::Grave() {
    descuento = 0.0;
    puntos = 0;
}

Grave::Grave(const Grave& orig) {
}

Grave::~Grave() {
}
void Grave::operator=(const Grave& orig){
    Infraccion::operator =(orig);
    descuento = orig.descuento;
    puntos = orig.puntos;
}
void Grave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int Grave::GetPuntos() const {
    return puntos;
}

void Grave::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Grave::GetDescuento() const {
    return descuento;
}

bool Grave::lee(ifstream &arch, int cod){
    bool encontrado = Infraccion::lee(arch, cod);
    if (encontrado) {
        arch >> descuento;
        arch.get();
        arch >> puntos;
        arch.get();
    }
    return encontrado;
}

void Grave::imprime(ofstream &arch) {
    arch << setw(10) << descuento << setw(10) << puntos << setw(10) << 0 << endl;
}