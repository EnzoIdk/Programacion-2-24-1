/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   sinreceta.cpp
 * Author: aml
 * 
 * Created on 29 de mayo de 2024, 09:14 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "sinreceta.h"

sinreceta::sinreceta() {
    nombre=nullptr;
    dni=0;
}

sinreceta::~sinreceta() {
    if(nombre!=nullptr) delete nombre;
}

void sinreceta::SetNombre(const char *nomb) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void sinreceta::GetNombre(char *nomb) const {
    if(nombre==nullptr) nomb[0]=0;
    else strcpy(nomb,nombre);
}

void sinreceta::SetDni(int dni) {
    this->dni = dni;
}

int sinreceta::GetDni() const {
    return dni;
}

void sinreceta::asignarDatos(int codMedicamento,int cantidad,int fecha,int dniCli,
        const char *nombreCli){
    medicamento::asignarDatos(codMedicamento,cantidad,fecha);
    SetDni(dniCli);
    SetNombre(nombreCli);
}

void sinreceta::imprimir(ofstream &arch){
    char nombreCli[60];
    medicamento::imprimir(arch);
    GetNombre(nombreCli);
    arch<<setw(9)<<GetDni()<<setw(5)<<' '<<nombreCli<<endl;
}

