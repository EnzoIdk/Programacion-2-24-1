/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Emergencia.cpp
 * Author: Enzo
 * 
 * Created on 13 de junio de 2024, 10:44 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Emergencia.h"
#include "Paciente.h"

Emergencia::Emergencia() {
    nombreRef=nullptr;
}

Emergencia::~Emergencia() {
    if(nombreRef!=nullptr) delete nombreRef;
}

void Emergencia::SetNombreRef(const char *cad) {
    if(nombreRef!=nullptr) delete nombreRef;
    nombreRef=new char[strlen(cad)+1];
    strcpy(nombreRef,cad);
}

void Emergencia::GetNombreRef(char *cad) const {
    if(nombreRef==nullptr) cad[0]=0;
    else strcpy(cad,nombreRef);
}

void Emergencia::SetTelefonoRef(int telefonoRef) {
    this->telefonoRef = telefonoRef;
}

int Emergencia::GetTelefonoRef() const {
    return telefonoRef;
}

void Emergencia::lee(ifstream &arch){
    Paciente::lee(arch);
    char cad[60];
    arch.getline(cad,60,',');
    SetNombreRef(cad);
    arch>>telefonoRef;
    arch.get();
}

int Emergencia::getPrioridad() const{
    return 3;
}

void Emergencia::imprime(ofstream &arch){
    Paciente::imprime(arch);
    arch<<setw(4)<<' '<<left<<setw(24)<<nombreRef<<right<<setw(10)<<telefonoRef<<endl;
}

bool Emergencia::tieneSeguro() const{
    return false;
}