/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: ISA
 * 
 * Created on 24 de mayo de 2024, 10:14 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Libro.h"

Libro::Libro() {
    alto = 0;
    ancho = 0;
    codigo = nullptr;
    nombre = nullptr;
    colocado = false;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
    if(nombre != nullptr)delete nombre;
    if(codigo != nullptr)delete codigo;
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

void Libro::SetCodigo(char *cad){
    if(codigo != nullptr)delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo,cad);
}
void Libro::GetCodigo(char *cad) const{
    if(codigo != nullptr)
        strcpy(cad,codigo);
}
bool Libro::IsNotNullCodigo() const{
    bool IsNotNull = true;
    if(codigo == nullptr)IsNotNull = false;
    return IsNotNull;
}
void Libro::SetNombre(char *cad){
    if(nombre != nullptr)delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}
void Libro::GetNombre(char *cad) const{
    if(nombre != nullptr)
        strcpy(cad,nombre);
}


ifstream & operator>>(ifstream &arch, class Libro &Lib){
    char cadena[120],c;
    int ancho,alto;
    arch.getline(cadena,12,',');
    if(not arch.eof()){
        Lib.SetCodigo(cadena);
        arch.getline(cadena,120,',');
        Lib.SetNombre(cadena);
        arch >> ancho >> c >> alto;
        arch.get();
        Lib.SetAncho(ancho);
        Lib.SetAlto(alto);
    }
    return arch;
}
ofstream & operator<<(ofstream &arch, const class Libro &Lib){
    char cadena[120];
    Lib.GetCodigo(cadena);
    arch << setw(10) << cadena << setw(60);
    if(Lib.IsColocado()){
        Lib.GetNombre(cadena);
        arch << cadena;
    }else arch << "NO SE PUDO COLOCAR";
    arch <<right << setw(5) << Lib.GetAncho() 
            << setw(5) << Lib.GetAlto() << endl;
    return arch;
}

