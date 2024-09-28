/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Virtual.cpp
 * Author: Enzo
 * 
 * Created on 11 de junio de 2024, 08:35 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Virtual.h"

Virtual::Virtual() {
    licencia=nullptr;
    total=0;
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

void Virtual::SetLicencia(const char *cad) {
    if(licencia!=nullptr) delete licencia;
    licencia=new char[strlen(cad)+1];
    strcpy(licencia,cad);
}

void Virtual::GetLicencia(char *cad) const {
    if(licencia==nullptr) cad[0]=0;
    else strcpy(cad,licencia);
}

void Virtual::lee(ifstream &arch){
    char lic[10];
    Alumno::lee(arch);
    arch.getline(lic,10);
    SetLicencia(lic);
}

void Virtual::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch<<setw(12)<<licencia<<setw(10)<<total<<endl;    
}

void Virtual::actualizatotal(double costoCred){
    SetTotal(100);
    double monto=costoCred*GetCreditos();
    Alumno::SetTotal(monto+total);
}