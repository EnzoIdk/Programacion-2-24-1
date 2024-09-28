/* 
 * File:   Escala.cpp
 * Author: ramir
 * 
 * Created on 5 de junio de 2024, 02:44 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Escala.h"

Escala::Escala() {
    codigo = 0;
    precio = 0.0;
}

Escala::Escala(const Escala& orig) {
}

Escala::~Escala() {
}

void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}

