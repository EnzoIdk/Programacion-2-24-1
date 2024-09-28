/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Docente.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 02:08 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Docente.h"

Docente::Docente() {
    anexo=0;
}

void Docente::SetAnexo(int anexo) {
    this->anexo = anexo;
}

int Docente::GetAnexo() const {
    return anexo;
}

void Docente::leer(ifstream& arch){
    arch>>anexo;
}

void Docente::imprime(ofstream &arch){
    Usuario::imprime(arch);
    arch<<"Anexo: "<<anexo<<endl;
}