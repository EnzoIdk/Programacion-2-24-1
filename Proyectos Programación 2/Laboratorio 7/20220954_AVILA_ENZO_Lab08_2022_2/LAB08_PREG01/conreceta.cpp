/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   conreceta.cpp
 * Author: aml
 * 
 * Created on 29 de mayo de 2024, 09:03 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "conreceta.h"

conreceta::conreceta() {
    especialidad=nullptr;
    codmed=0;
}

conreceta::~conreceta() {
    if(especialidad!=nullptr) delete especialidad;
}

void conreceta::SetEspecialidad(const char *esp) {
    if(especialidad!=nullptr) delete especialidad;
    especialidad=new char[strlen(esp)+1];
    strcpy(especialidad,esp);
}

void conreceta::GetEspecialidad(char *esp) const {
    if(especialidad==nullptr) esp[0]=0;
    else strcpy(esp,especialidad);
}

void conreceta::SetCodmed(int codmed) {
    this->codmed = codmed;
}

int conreceta::GetCodmed() const {
    return codmed;
}

void conreceta::asignarDatos(int codMedicamento,int cantidad,int fecha,int codigoMed,
        const char *esp){
    medicamento::asignarDatos(codMedicamento,cantidad,fecha);
    SetCodmed(codigoMed);
    SetEspecialidad(esp);
}

void conreceta::imprimir(ofstream &arch){
    char esp[20];
    medicamento::imprimir(arch);
    GetEspecialidad(esp);
    arch<<setw(7)<<GetCodmed()<<setw(10)<<' '<<esp<<endl;
}