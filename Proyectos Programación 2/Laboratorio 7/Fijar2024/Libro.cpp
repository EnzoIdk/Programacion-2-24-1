/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: margo
 * 
 * Created on 29 de mayo de 2024, 9:13
 */

#include "Libro.h"
#include <cstring>
#include <iostream>
using namespace std;
Libro::Libro() {
    alto=0;
    ancho=0;
    codigo=nullptr;
    colocado=false;
    nombre=nullptr;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
    if (codigo!=nullptr) delete codigo;
    if (nombre!=nullptr) delete nombre;
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetNombre(const char* cod) {
    if (nombre!=nullptr) delete nombre;
    nombre=new char [strlen(cod)+1]{};
    strcpy(nombre, cod);
}

void Libro::GetNombre(char *cod) const {
    if (codigo==nullptr){
        cod[0]=0;
    }else{
        strcpy(cod, codigo);
    }
}

void Libro::SetCodigo(const char* cod) {
    if (codigo!=nullptr) delete codigo;
    codigo=new char [strlen(cod)+1]{};
    strcpy(codigo, cod);
}

void Libro::GetCodigo(char *cod )const {
    if (codigo==nullptr){
        cod[0]=0;
    }else{
        strcpy(cod, codigo);
    }
}

void Libro::lectura(ifstream&arch) {
        //MAT M001, Cálculo Integral, 3, 5, DESC12
    char cod[7]{};
    char desc[60]{};
    int anc;
    int alt;
    arch.getline(cod, 10, ',');
    if (arch.eof()) return;
    arch.getline(desc,60, ',');
    arch>>anc;
    arch.get();
    arch>>alt;
    arch.get();
    SetAlto(alt);
    SetAncho(anc);
    SetCodigo(cod);
    SetNombre(desc);
    cout<<nombre<<endl;
}

void Libro::agregarDatosLibro(Libro&lib) {
    int alt=lib.GetAlto();
    int anc=lib.GetAncho();
    char cod[60]{}, desc[60]{};
    lib.GetCodigo(cod);
    lib.GetNombre(desc);
    SetAlto(alt);
    SetAncho(anc);
    SetCodigo(cod);
    SetNombre(desc);
    SetColocado(true);
}


