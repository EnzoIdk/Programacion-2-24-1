/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Libro.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 18:44
 */

#include <iostream>
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
    char nombreTemp[100];
    int paginasTemp;
    double pesoTemp;
    //Cien anios de soledad,210,0.5,Gabriel Garcia Marquez
    arch.getline(nombreTemp, 100, ',');
    arch>>paginasTemp;
    arch.get();
    arch>>pesoTemp;
    arch.get();
    //
    this->SetNombre(nombreTemp);
    this->SetPeso(pesoTemp);
    this->SetPaginas(paginasTemp);
}

void Libro::imprime(ofstream& arch){
    char titTemp[100];
    this->GetNombre(titTemp);
    //
    arch<<"Titulo: "<<titTemp<<endl;
    arch<<"Peso: "<<this->GetPeso()<<endl;
}

//FUNCIONES
