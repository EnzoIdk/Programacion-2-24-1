/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Novela.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 18:51
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Novela.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

Novela::Novela() {
    autor=nullptr;
}

Novela::Novela(const class Novela &orig) {

}

Novela::~Novela() {
    if(autor!=nullptr) delete autor;
}

//GETTERS Y SETTERS
void Novela::SetAutor(char * cad) {
    if(autor!=nullptr) delete autor;
    autor=new char[strlen(cad)+1];
    strcpy(autor, cad);
}

void Novela::GetAutor(char * cad) const {
    if(autor==nullptr) cad[0]=0;
    else strcpy(cad, autor);
}

//METODOS
void Novela::lee(ifstream& arch){
    char autTemp[60];
    this->Libro::lee(arch);
    //Jose Maria Arguedas
    arch.getline(autTemp, 60, '\n');
    //
    this->SetAutor(autTemp);
}

void Novela::actualiza(int aa){
    return;
}

void Novela::imprime(ofstream& arch){
    char autTemp[100];
    this->GetAutor(autTemp);
    //
    this->Libro::imprime(arch);
    //
    arch<<"Autor: "<<autTemp<<endl;
}

//FUNCIONES
