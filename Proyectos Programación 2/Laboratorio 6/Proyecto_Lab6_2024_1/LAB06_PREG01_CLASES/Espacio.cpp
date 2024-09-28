/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Espacio.cpp
 * Author: ISA
 * 
 * Created on 24 de mayo de 2024, 10:14 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Espacio.h"

Espacio::Espacio() {
    posx = -1;
    posy = -1;
    contenido = ' ';
}

Espacio::Espacio(const Espacio& orig) {
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

ofstream & operator<<(ofstream &arch, const class Espacio &Esp){
    arch << '[' << Esp.GetContenido() << ']';
    return arch;
}
