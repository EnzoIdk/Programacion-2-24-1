/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Novela.cpp
 * Author: margo
 * 
 * Created on 20 de junio de 2024, 7:42
 */

#include "Novela.h"
#include <cstring >
using namespace std;
Novela::Novela() {
      autor=nullptr;
}

Novela::Novela(const Novela& orig) {

}

Novela::~Novela() {
     if (autor!=nullptr) delete autor;
}

void Novela::SetAutor(const char* aut) {
    if (autor!=nullptr) delete autor;
    autor=new char[strlen(aut)+1]{};
    strcpy(autor, aut);
}

void Novela::GetAutor(char*aut) const {
    if (autor!=nullptr) strcpy(aut, autor);
    else aut[0]=0;
}

void Novela::lee(ifstream&arch) {
    Libro::lee(arch);
     char ti[100]{};
    arch.getline(ti, 100);
    SetAutor(ti);
}

void Novela::actualiza() {
//    if (anho<2020) 
}

void Novela::imprime(ofstream&arch) {
 Libro::imprime(arch);
    arch<<"Autor: "<<autor<<endl;
}
