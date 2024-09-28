/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Virtual.cpp
 * Author: Enzo
 * 
 * Created on 28 de mayo de 2024, 09:54 PM
 */

#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
#include "Virtual.h"

Virtual::Virtual() {
    licencia=nullptr;
    total=100;
}

Virtual::~Virtual() {
    if(licencia!=nullptr) delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char *lic) {
    if(licencia!=nullptr) delete licencia;
    licencia=new char[strlen(lic+1)];
    strcpy(licencia,lic);
}

void Virtual::GetLicencia(char *lic) const {
    if(licencia==nullptr) lic[0]=0;
    else strcpy(lic,licencia);
}

void Virtual::leerDatos(ifstream &arch){
    char lic[15];
    Alumno::leerDatos(arch);
    arch.getline(lic,15,'\n');
    SetLicencia(lic);
}

void Virtual::actualiza(double monto){
    Alumno::SetTotal(monto+total);
}

void Virtual::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch<<setw(15)<<licencia<<setw(10)<<Alumno::GetTotal()<<endl;
}