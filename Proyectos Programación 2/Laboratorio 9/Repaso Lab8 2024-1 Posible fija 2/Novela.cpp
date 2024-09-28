/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Novela.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 21:12
 */

#include <iostream>
#include <fstream>
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
    char autorTemp[100];
    //
    this->Libro::lee(arch);
    arch.getline(autorTemp, 100, '\n');
    //
    this->SetAutor(autorTemp);
}

void Novela::actualiza(){
    return;
}

void Novela::imprime(ofstream& arch){
    char autTemp[100];
    this->GetAutor(autTemp);
    //
    this->Libro::imprime(arch);
    arch<<"Autor: "<<autTemp<<endl;
}


//FUNCIONES
