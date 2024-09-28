/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Novela.cpp
 * Author: Lucas
 * 
 * Created on 8 de julio de 2024, 07:47 PM
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "Novela.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
Novela::Novela() {

}

Novela::Novela(const class Novela &orig) {

}

Novela::~Novela() {

}

//GETTERS Y SETTERS
void Novela::SetAutor(string autor) {
    this->autor = autor;
}

string Novela::GetAutor() const {
    return autor;
}

//METODOS
void Novela::leer(ifstream &arch){
    string autTemp;
    //N,La Iliada,200,1.5,Homero
    this->Libro::leer(arch);
    //Homero
    getline(arch, autTemp, '\n');
    //GUARDAMOS
    this->SetAutor(autTemp);
}

void Novela::imprimir(ofstream &arch){
    this->Libro::imprimir(arch);
    arch<<"Autor: "<<this->GetAutor()<<endl;
}

void Novela::actualiza(int aa){
    
}
