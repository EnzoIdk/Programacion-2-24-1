/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Novela.cpp
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
#include "Novela.h"

Novela::Novela() {
    tipo=nullptr;
}

Novela::~Novela() {
    if(tipo!=nullptr) delete tipo;
}

void Novela::SetPeso(double peso) {
    this->peso = peso;
}

double Novela::GetPeso() const {
    return peso;
}

void Novela::SetTipo(const char *cad) {
    if(tipo!=nullptr) delete tipo;
    tipo=new char[strlen(cad)+1];
    strcpy(tipo,cad);
}

void Novela::GetTipo(char *cad) const {
    if(tipo==nullptr) cad[0]=0;
    else strcpy(cad,tipo);
}

void Novela::leerLib(ifstream &arch){
    Libro::leerLib(arch);
    char aux[20];
    arch.get();
    arch.getline(aux,20,',');
    SetTipo(aux);
    arch.get();
    arch>>peso;
    arch.get();
    Libro::SetPeso(peso);
}

void Novela::imprimirLib(ofstream &arch){
    Libro::SetPeso(peso);
    Libro::imprimirLib(arch);
    arch<<setw(3)<<' '<<tipo<<endl;
}