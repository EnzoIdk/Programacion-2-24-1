/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tercera.cpp
 * Author: Jeremy Lopez Galindo
 * 
 * Created on 4 de diciembre de 2023, 08:24 PM
 */

#include "Tercera.h"

Tercera::Tercera() {
    porcentaje = 0;
}

Tercera::Tercera(const Tercera& orig) {
}

Tercera::~Tercera() {
}

double Tercera::getPorcentaje() const {
    return porcentaje;
}

void Tercera::setPorcentaje(double p) {
    porcentaje = p;
}

void Tercera::actualiza() {
    setVez(3);
    if(getCreditos()<=3)setPorcentaje(50);
    else setPorcentaje(100);
}

void Tercera::imprime(ofstream& out) {
    CursoAlumno::imprime(out);
    out<<setw(10)<<getPorcentaje()<<endl;
}
