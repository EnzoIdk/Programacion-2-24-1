/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Paciente.cpp
 * Author: Enzo
 * 
 * Created on 13 de junio de 2024, 10:44 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Paciente.h"

Paciente::Paciente() {
    nombre=nullptr;
}

Paciente::~Paciente() {
    if(nombre!=nullptr) delete nombre;
}

void Paciente::SetNombre(const char *cad) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Paciente::GetNombre(char *cad) const {
    if(nombre==nullptr) cad[0]=0;
    else strcpy(cad,nombre);
}

void Paciente::SetDni(int dni) {
    this->dni = dni;
}

int Paciente::GetDni() const {
    return dni;
}

void Paciente::SetCodMed(int codMed) {
    this->codMed = codMed;
}

int Paciente::GetCodMed() const {
    return codMed;
}

void Paciente::lee(ifstream &arch){
    char cad[60];
    arch>>dni;
    arch.get();
    arch.getline(cad,60,',');
    SetNombre(cad);
    arch>>codMed;
    arch.get();
}

void Paciente::imprime(ofstream &arch){
    arch<<dni<<setw(2)<<' '<<left<<setw(50)<<nombre<<right<<setw(6)<<codMed;
}