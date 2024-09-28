/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Primera.cpp
 * Author: Jeremy Lopez Galindo
 * 
 * Created on 4 de diciembre de 2023, 08:21 PM
 */

#include "Primera.h"

Primera::Primera() {
    codacceso = nullptr;
}

Primera::Primera(const Primera& orig) {
}

Primera::~Primera() {
    if(codacceso)delete codacceso;
}

void Primera::getCodAcceso(char* cad) {
    if(codacceso == nullptr)cad[0] = 0;
    else strcpy(cad,codacceso);
}

void Primera::setCodAcceso(char* cad) {
    if(codacceso)delete codacceso;
    codacceso = new char[strlen(cad)+1];
    strcpy(codacceso,cad);
}

void Primera::imprime(ofstream& out) {
    CursoAlumno::imprime(out);
    char cod[20];
    getCodCurso(cod);
    out<<setw(10)<<getCodigo()<<cod<<endl;
    //No se usar el sprintf xd
}
