/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Enzo
 * 
 * Created on 29 de mayo de 2024, 04:05 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Libro.h"

Libro::Libro() {
    codigo=nullptr;
    nombre=nullptr;
    colocado=true;
}

Libro::~Libro() {
    if(codigo!=nullptr) delete codigo;
    if(nombre!=nullptr) delete nombre;
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(const char *nomb) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Libro::GetNombre(char *nomb) const {
    if(nombre==nullptr) nomb[0]=0;
    else strcpy(nomb,nombre);
}

void Libro::SetCodigo(const char *cod) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cod)+1];
    strcpy(codigo,cod);
}

void Libro::GetCodigo(char *cod) const {
    if(codigo==nullptr) cod[0]=0;
    else strcpy(cod,codigo);
}

void operator >>(ifstream &arch,class Libro &lib){
    char codigo[8],nombre[60];
    int ancho,alto;
    arch.getline(codigo,8,',');
    if(arch.eof()) return;
    arch.getline(nombre,60,',');
    arch>>ancho;
    arch.get();
    arch>>alto;
    arch.get();
    lib.SetCodigo(codigo);
    lib.SetNombre(nombre);
    lib.SetAlto(alto);
    lib.SetAncho(ancho);
}

void operator <<(ofstream &arch,class Libro &lib){
    char codigo[8],nombre[60];
    lib.GetCodigo(codigo);
    lib.GetNombre(nombre);
    arch<<codigo<<setw(2)<<' '<<left<<setw(35);
    if(lib.IsColocado()) arch<<nombre<<right;
    else arch<<"NO SE PUDO COLOCAR"<<right;
    arch<<setw(3)<<lib.GetAncho()<<setw(5)<<lib.GetAlto()<<endl;
}