/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matematica.cpp
 * Author: margo
 * 
 * Created on 29 de mayo de 2024, 9:21
 */

#include "Matematica.h"
#include "Libro.h"
#include <cstring>
using namespace std;
Matematica::Matematica() {
    codigo=nullptr;
}

Matematica::Matematica(const Matematica& orig) {
}

Matematica::~Matematica() {
    if (codigo!=nullptr) delete codigo;
}

void Matematica::SetCodigo(const char* cod) {
    if (codigo!=nullptr) delete codigo;
    codigo=new char [strlen(cod)+1]{};
    strcpy(codigo, cod);
}

void Matematica::GetCodigo( char *cod) const {
    if (codigo==nullptr){
        cod[0]=0;
    }else{
        strcpy(cod, codigo);
    }
}

void Matematica::lectura(ifstream&arch) {
    //    //MAT M001, Cálculo Integral, 3, 5, 
    char cod[10]{};
    Libro::lectura(arch);
    arch.getline(cod, 10);
    SetCodigo(cod);
}

