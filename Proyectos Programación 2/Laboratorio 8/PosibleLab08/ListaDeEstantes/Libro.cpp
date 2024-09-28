/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Enzo
 * 
 * Created on 13 de junio de 2024, 08:23 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>   
#include <cstring>
using namespace std;
#include "Libro.h"

Libro::Libro() {
    nombre=nullptr;
    codigo=nullptr;
    colocado=false;
    peso=0;
}

Libro::~Libro() {
    if(nombre!=nullptr) delete nombre;
    if(codigo!=nullptr) delete codigo;
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetNombre(const char *cad) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Libro::GetNombre(char *cad) const {
    if(nombre==nullptr) cad[0]=0;
    else strcpy(cad,nombre);
}

void Libro::SetCodigo(const char *cad) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cad)+1];
    strcpy(codigo,cad);
}

void Libro::GetCodigo(char *cad) const {
    if(codigo==nullptr) cad[0]=0;
    else strcpy(cad,codigo);
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

void Libro::leerLib(ifstream &arch){
    char aux[60];
    arch.get();
    arch.getline(aux,10,',');
    SetCodigo(aux);
    arch.get();
    arch.getline(aux,60,',');
    SetNombre(aux);
    arch>>ancho;
    arch.get();
    arch>>alto;
    arch.get();
}

void Libro::imprimirLib(ofstream &arch){
    arch<<codigo<<setw(3)<<' '<<left<<setw(40)<<nombre<<right<<setw(2)<<
            ancho<<setw(4)<<alto<<setw(6)<<peso;
}
