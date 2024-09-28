/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Espacio.cpp
 * Author: margo
 * 
 * Created on 29 de mayo de 2024, 9:13
 */

#include "Espacio.h"
#include <cstring>
using namespace std;
Espacio::Espacio() {
    contenido = ' ';
    posx= 0;
    posy= 0;
}

Espacio::Espacio(const Espacio& orig) {
}

Espacio::~Espacio() {
}

void Espacio::SetPosy(int posy) {
    this->posy = posy;
}

int Espacio::GetPosy() const {
    return posy;
}

void Espacio::SetPosx(int posx) {
    this->posx = posx;
}

int Espacio::GetPosx() const {
    return posx;
}

void Espacio::SetContenido(char contenido) {
    this->contenido = contenido;
}

char Espacio::GetContenido() const {
    return contenido;
}

