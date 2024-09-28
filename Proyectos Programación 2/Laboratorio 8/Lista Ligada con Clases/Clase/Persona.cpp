/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.cpp
 * Author: Enzo
 * 
 * Created on 9 de junio de 2024, 09:33 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Persona.h"

Persona::Persona() {
    nombre=nullptr;
}

Persona::Persona(const Persona& orig) {
}

Persona::~Persona() {
    if(nombre!=nullptr) delete nombre;
}

void Persona::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
    return sueldo;
}

void Persona::SetNombre(const char *cad) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Persona::GetNombre(char *cad) const {
    if(nombre==nullptr) cad[0]=0;
    else strcpy(cad,nombre);
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}

void Persona::operator =(const class Persona &per){
    char nomb[60];
    dni=per.GetDni();
    per.GetNombre(nomb);
    SetNombre(nomb);
    sueldo=per.GetSueldo();
}

bool Persona::operator >(const class Persona &per){
    return dni>per.GetDni();
}

ifstream & operator >>(ifstream &arch,class Persona &per){
    int dni;
    char nomb[60];
    double sueldo;
    arch>>dni;
    if(arch.eof()) return arch;
    arch.get();
    arch.getline(nomb,60,',');
    arch>>sueldo;
    per.SetDni(dni);
    per.SetNombre(nomb);
    per.SetSueldo(sueldo);
    return arch;
}

ofstream & operator <<(ofstream &arch,const class Persona &per){
    char nomb[60];
    arch<<setprecision(2)<<fixed;
    per.GetNombre(nomb);
    arch<<left<<setw(10)<<per.GetDni()<<setw(40)<<nomb<<right<<
            setw(10)<<per.GetSueldo()<<endl;
    return arch;
}