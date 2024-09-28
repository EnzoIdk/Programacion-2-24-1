/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Fisica.cpp
 * Author: Enzo
 * 
 * Created on 30 de mayo de 2024, 10:32 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Fisica.h"

Fisica::Fisica() {
    profesor=nullptr;
}

Fisica::~Fisica() {
    if(profesor!=nullptr) delete profesor;
}

void Fisica::SetProfesor(const char *profe) {
    if(profesor!=nullptr) delete profesor;
    profesor=new char[strlen(profe)+1];
    strcpy(profesor,profe);
}

void Fisica::GetProfesor(char *profe) const {
    if(profesor==nullptr) profe[0]=0;
    else strcpy(profe,profesor);
}

void Fisica::leerDatos(ifstream &arch){
    char profe[20];
    Libro::leerDatos(arch);
    arch.get();
    arch.getline(profe,20);
    SetProfesor(profe);
}
