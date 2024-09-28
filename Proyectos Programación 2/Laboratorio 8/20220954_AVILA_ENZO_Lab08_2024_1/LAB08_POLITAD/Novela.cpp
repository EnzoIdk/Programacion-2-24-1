/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Novela.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 08:06 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Novela.h"
#include "Libro.h"
Novela::Novela() {
    autor=nullptr;
}

Novela::~Novela() {
    if(autor!=nullptr) delete autor;
}

void Novela::SetAutor(const char *cad) {
    if(autor!=nullptr) delete autor;
    autor=new char[strlen(cad)+1];
    strcpy(autor,cad);
}

void Novela::GetAutor(char *cad) const {
    if(autor==nullptr) cad[0]=0;
    else strcpy(cad,autor);
}

void Novela::lee(ifstream &arch){
    Libro::lee(arch);
    char cad[60];
    arch.getline(cad,60);
    SetAutor(cad);
}

void Novela::actualiza(){
    //no hace nada
}

void Novela::imprime(ofstream &arch){
    Libro::imprime(arch);
    arch<<"Autor: "<<autor<<endl<<endl;
}