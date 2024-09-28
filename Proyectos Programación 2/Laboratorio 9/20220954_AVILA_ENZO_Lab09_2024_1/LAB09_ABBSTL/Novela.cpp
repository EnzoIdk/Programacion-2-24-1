/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Novela.cpp
 * Author: aml
 * 
 * Created on 24 de junio de 2024, 09:48 AM
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

void Novela::lee(ifstream& arch){
    Libro::lee(arch);
    char cad[60];
    arch.getline(cad,60);
    SetAutor(cad);
}

void Novela::imprime(ofstream& arch){
    Libro::imprime(arch);
    arch<<"Autor: "<<autor<<endl<<endl;
}