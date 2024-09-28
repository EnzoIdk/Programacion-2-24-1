/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 08:05 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Libro.h"

Libro::Libro() {
    nombre=nullptr;
}

Libro::~Libro() {
    if(nombre!=nullptr) delete nombre;
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
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

void Libro::lee(ifstream &arch){
    char cad[60];
    arch.getline(cad,60,',');
    SetNombre(cad);
    arch>>paginas;
    arch.get();
    arch>>peso;
    arch.get(); //','
}

void Libro::imprime(ofstream &arch){
    arch<<"Titulo: "<<nombre<<endl;
    arch<<"Peso: "<<setw(6)<<peso<<setw(3)<<' '<<"Paginas: "<<paginas<<endl;
    
}