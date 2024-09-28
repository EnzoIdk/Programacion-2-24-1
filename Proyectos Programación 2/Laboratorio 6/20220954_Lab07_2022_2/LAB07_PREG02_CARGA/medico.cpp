/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medico.cpp
 * Author: Enzo
 * 
 * Created on 23 de mayo de 2024, 07:21 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

#include "medico.h"

medico::medico() {
    codigo=0;
    nombre=nullptr;
    tarifa=0;
}

medico::medico(const medico& orig) {
}

medico::~medico() {
    if(nombre!=nullptr) delete nombre;
}

void medico::SetTarifa(double tarifa) {
    this->tarifa = tarifa;
}

double medico::GetTarifa() const {
    return tarifa;
}

void medico::SetNombre(const char *nomb) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void medico::GetNombre(char *nomb) const {
    if(nombre==nullptr) nomb[0]=0;
    else strcpy(nomb,nombre);
}

void medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medico::GetCodigo() const {
    return codigo;
}

void operator >>(ifstream &arch,medico &med){
    int cod;
    char nomb[60];
    double tar;
    arch>>cod;
    if(arch.eof()) return;
    arch.get();
    arch.getline(nomb,60,',');
    arch>>tar;
    med.SetCodigo(cod);
    med.SetNombre(nomb);
    med.SetTarifa(tar);
}