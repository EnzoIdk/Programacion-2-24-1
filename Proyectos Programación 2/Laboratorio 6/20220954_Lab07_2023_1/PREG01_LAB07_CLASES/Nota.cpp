/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Nota.cpp
 * Author: Enzo
 * 
 * Created on 23 de mayo de 2024, 04:25 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "Nota.h"

Nota::Nota() {
    codcurso=nullptr;
    nota=0;
}

Nota::Nota(const Nota& orig) {
}

Nota::~Nota() {
    if(codcurso!=nullptr) delete codcurso;
}

void Nota::SetNota(int nota) {
    this->nota = nota;
}

int Nota::GetNota() const {
    return nota;
}

void Nota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Nota::GetCiclo() const {
    return ciclo;
}

void Nota::SetCodcurso(const char *cod) {
    if(codcurso!=nullptr) delete codcurso;
    codcurso=new char[strlen(cod)+1];
    strcpy(codcurso,cod);
}

void Nota::GetCodcurso(char *cod) const {
    if(codcurso==nullptr) cod[0]=0;
    strcpy(cod,codcurso);
}

