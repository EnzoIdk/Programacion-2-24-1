/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: Enzo
 * 
 * Created on 25 de junio de 2024, 12:37 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Alumno.h"

Alumno::Alumno() {
    nombre=nullptr;
    promedio=0;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
    if(nombre!=nullptr) delete nombre;
}

void Alumno::SetPromedio(double promedio) {
    this->promedio = promedio;
}

double Alumno::GetPromedio() const {
    return promedio;
}

void Alumno::SetNombre(const char *cad) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Alumno::GetNombre(char *cad) const {
    if(nombre==nullptr) cad[0]=0;
    else strcpy(cad,nombre);
}

void Alumno::SetCodigo_alumno(int codigo_alumno) {
    this->codigo_alumno = codigo_alumno;
}

int Alumno::GetCodigo_alumno() const {
    return codigo_alumno;
}

void operator >>(ifstream &arch,class Alumno &alu){
    int cod;
    char cad[60];
    arch>>cod;
    if(arch.eof()) return;
    alu.SetCodigo_alumno(cod);
    arch.get();
    arch.getline(cad,60);
    alu.SetNombre(cad);
}

void Alumno::imprimeAlumno(ofstream& arch){
    arch<<setw(10)<<codigo_alumno<<setw(3)<<' '<<left<<setw(40)<<nombre<<
            right<<setw(6)<<promedio<<endl;
}