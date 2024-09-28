/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Segunda.cpp
 * Author: Jeremy Lopez Galindo
 * 
 * Created on 4 de diciembre de 2023, 08:23 PM
 */

#include "Segunda.h"

Segunda::Segunda() {
    creditos = 0;
}

Segunda::Segunda(const Segunda& orig) {
}

Segunda::~Segunda() {
}

double Segunda::getCreditosS() const {
    return creditos;
}

void Segunda::setCreditosS(double c) {
    creditos = c;
}

void Segunda::actualiza() {
    setVez(2);
    if(getCreditos()<=3)setCreditosS(1);
    else setCreditosS(1.5);
}

void Segunda::imprime(ofstream& out) {
    CursoAlumno::imprime(out);
    out<<setw(10)<<getCreditosS()<<endl;
}
