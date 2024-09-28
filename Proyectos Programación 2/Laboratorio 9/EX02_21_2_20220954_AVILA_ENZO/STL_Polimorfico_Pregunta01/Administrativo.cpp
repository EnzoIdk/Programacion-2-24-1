/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Administrativo.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 02:07 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Administrativo.h"

Administrativo::Administrativo() {
    area=nullptr;
}

Administrativo::~Administrativo() {
    if(area!=nullptr) delete area;
}

void Administrativo::SetArea(const char *cad) {
    if(area!=nullptr) delete area;
    area=new char[strlen(cad)+1];
    strcpy(area,cad);
}

void Administrativo::GetArea(char *cad) const {
    if(area==nullptr) cad[0]=0;
    else strcpy(cad,area);
}

void Administrativo::leer(ifstream& arch){
    char cad[60];
    arch.getline(cad,60);
    SetArea(cad);
}

void Administrativo::imprime(ofstream& arch){
    Usuario::imprime(arch);
    arch<<"Area: "<<area<<endl;
}

