/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Libro.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 21:06
 */

#include <iostream>
#include <fstream>
using namespace std;
#include <cstring>

#include "Libro.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
Libro::Libro() {
    nombre=nullptr;
}

Libro::Libro(const class Libro &orig) {

}

Libro::~Libro() {
    if(nombre!=nullptr) delete nombre;
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

void Libro::SetNombre(char * cad) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Libro::GetNombre(char * cad) const {
    if(nombre==nullptr) cad[0]=0;
    else strcpy(cad, nombre);
}

//METODOS
void Libro::lee(ifstream& arch){
    char nomTemp[100];
    int pagTemp;
    double pesoTemp;
    //LA ENCICLOPEDIA DE LOS DINOSAURIOS,448,2,36225,2018
    arch.getline(nomTemp, 100, ',');
    arch>>pagTemp;
    arch.get();
    arch>>pesoTemp;
    arch.get();
    //
    this->SetNombre(nomTemp);
    this->SetPeso(pesoTemp);
    this->SetPaginas(pagTemp);
}

void Libro::imprime(ofstream& arch){
    char titTemp[100];
    this->GetNombre(titTemp);
    //
    arch<<"Titulo: "<<titTemp<<endl;
    arch<<"Peso: "<<this->GetPeso()<<endl;
}

//FUNCIONES
