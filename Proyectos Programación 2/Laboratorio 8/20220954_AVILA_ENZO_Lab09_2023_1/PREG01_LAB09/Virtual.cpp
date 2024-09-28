/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Virtual.cpp
 * Author: Enzo
 * 
 * Created on 7 de junio de 2024, 04:37 PM
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

void Virtual::SetLicencia(const char *lic) {
    if(licencia!=nullptr) delete licencia;
    licencia=new char[strlen(lic)+1];
    strcpy(licencia,lic);
}

void Virtual::GetLicencia(char *lic) const {
    if(licencia==nullptr) lic[0]=0;
    else strcpy(lic,licencia);
}

void Virtual::lee(ifstream &arch){
    char lic[10];
    Alumno::lee(arch);
    arch>>lic;
    arch.get();
    SetLicencia(lic);
}

void Virtual::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch<<setw(12)<<licencia<<setw(10)<<Alumno::GetTotal()<<endl;
}

void Virtual::actualizatotal(double costoCred){
    double monto=costoCred*GetCreditos();
    total=100;
    Alumno::SetTotal(monto+total);
}