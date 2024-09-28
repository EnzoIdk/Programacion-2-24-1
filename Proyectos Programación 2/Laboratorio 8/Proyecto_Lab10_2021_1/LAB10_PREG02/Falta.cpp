/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Falta.cpp
 * Author: ISA
 * 
 * Created on 6 de junio de 2024, 03:44 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Falta.h"
#define NO_ENCONTRADO -1

Falta::Falta() {
    fecha = 0;
    licencia = 0;
    placa = nullptr;
}

Falta::Falta(const Falta& orig) {
}

Falta::~Falta() {
    if (placa != nullptr)delete placa;
}
void Falta::operator=(const Falta& orig){
    fecha = orig.fecha;
    licencia = orig.licencia;
    SetPlaca(orig.placa);
}
void Falta::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Falta::GetFecha() const {
    return fecha;
}

void Falta::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Falta::GetLicencia() const {
    return licencia;
}

void Falta::SetPlaca(char *cad) {
    if (placa != nullptr)delete placa;
    placa = new char[strlen(cad) + 1];
    strcpy(placa, cad);
}

void Falta::GetPlaca(char *cad) const {
    if (placa != nullptr)
        strcpy(cad, placa);
}

int Falta::operator<=(ifstream &arch) {
    char cadena[12], c;
    int dd, mm, aaaa, codinf;
    arch >> licencia;
    if(arch.eof())return NO_ENCONTRADO;
    arch.get();
    arch.getline(cadena,12,',');
    SetPlaca(cadena);
    arch >> dd >> c >> mm >> c >> aaaa >> c >> codinf;
    fecha = dd + 100 * mm + 10000 * aaaa;
    return codinf;
}

void Falta::operator>=(ofstream &arch){
    ImprimirFecha(arch);
    arch << left <<setw(12) << licencia << setw(10) << placa;
}

void Falta::ImprimirFecha(ofstream &arch){
    arch << right << setfill('0')<< setw(2)<< fecha%100 << '/' << setw(2)
            << (fecha/100)%100 << '/' << setw(4) << fecha/10000 <<setfill(' ')
            << setw(5) << ' ';
}