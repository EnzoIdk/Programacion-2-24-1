/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 08:56 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Libro.h"

Libro::Libro() {
    nombre=nullptr;
}

Libro::Libro(const Libro& orig) {
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

void Libro::lee(ifstream& arch){
    char cad[60],car;
    arch.getline(cad,60,',');
    SetNombre(cad);
    arch>>paginas>>car>>peso>>car;
}

void Libro::imprime(ofstream& arch){
    arch<<"Titulo: "<<nombre<<endl;
    arch<<"Peso: "<<setw(5)<<peso<<endl;
}
