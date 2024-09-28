/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: margo
 * 
 * Created on 20 de junio de 2024, 7:38
 */

#include "Libro.h"
#include "Biblioteca.h"
#include <cstring >
#include <iostream>
using namespace std;
Libro::Libro() {
    nombre=nullptr;
    paginas=0;
    peso=0;
}

Libro::Libro(const Libro& orig) {
    nombre= nullptr;
    *this = orig;
}

Libro::~Libro() {
    if (nombre!=nullptr) delete nombre;

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

void Libro::SetNombre(const char* nomb) {
    if (nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nomb)+1]{};
    strcpy(nombre, nomb);
}

void Libro::GetNombre(char*nomb) const {
    if (nombre!=nullptr) strcpy(nomb, nombre);
    else nomb[0]=0;
}

void Libro::lee(ifstream&arch) {
    //N,El Maestro y Margarita,120,
    char ti[100]{};
    arch.getline(ti, 100, ',');
    arch>>paginas;
    arch.get();
    arch>>peso;
    SetNombre(ti);
    arch.get();
   
}

void Libro::actualizar() {
    
}

void Libro::imprime(ofstream&arch) {
    arch<<"Nombre: "<<nombre<<endl;
    arch<<"Paginas: "<<paginas<<endl;
    arch<<"Peso: "<<peso<<endl;
}
