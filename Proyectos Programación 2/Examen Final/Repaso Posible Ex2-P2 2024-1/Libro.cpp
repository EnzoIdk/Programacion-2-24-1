/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Libro.cpp
 * Author: Lucas
 * 
 * Created on 8 de julio de 2024, 07:44 PM
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "Libro.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
Libro::Libro() {

}

Libro::Libro(const class Libro &orig) {

}

Libro::~Libro() {

}

//GETTERS Y SETTERS
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

void Libro::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Libro::GetNombre() const {
    return nombre;
}

//METODOS
void Libro::leer(ifstream &arch){
    string nomTemp;
    int pagTemp;
    double pesTemp;
    //N,Confesiones de una mascara,80,0.8,Yukio Mishima
    getline(arch, nomTemp, ',');
    arch>>pagTemp;
    arch.get(); //,
    arch>>pesTemp;
    arch.get(); //,
    //GUARDAMOS
    this->SetPeso(pesTemp);
    this->SetNombre(nomTemp);
    this->SetPaginas(pagTemp);
}

void Libro::imprimir(ofstream &arch){
    arch<<"Titulo: "<<this->GetNombre()<<endl;
    arch<<"Peso: "<<this->GetPeso()<<endl;
}