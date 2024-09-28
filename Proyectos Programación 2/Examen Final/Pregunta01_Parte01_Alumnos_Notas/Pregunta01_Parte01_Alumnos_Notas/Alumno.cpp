/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: margo
 * 
 * Created on 8 de julio de 2024, 18:41
 */

#include "Alumno.h"
#include <cstring>
using namespace std;

Alumno::Alumno() {
    nombre=nullptr;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
    if (nombre!=nullptr) delete nombre;
}

void Alumno::SetPromedio(double promedio) {
    this->promedio = promedio;
}

double Alumno::GetPromedio() const {
    return promedio;
}

void Alumno::SetNombre(char* nomb) {
    if (nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nomb)+1]{};
    strcpy(nombre, nomb);
}

void Alumno::GetNombre(char *nomb) const {
    if (nombre!=nullptr) strcpy(nomb, nombre);
    else nomb[0]=0;
}

void Alumno::SetCodigo_alumno(int codigo_alumno) {
    this->codigo_alumno = codigo_alumno;
}

int Alumno::GetCodigo_alumno() const {
    return codigo_alumno;
}

void operator >>(ifstream &arch, Alumno &al){
    int codigo;
    char nombre[100]{};
    arch>>codigo;
    if(arch.eof()) return;
    arch.get();
    arch.getline(nombre, 100);
    al.SetCodigo_alumno(codigo);
    al.SetNombre(nombre);
}

void operator <<(ofstream&arch, Alumno &al){
    arch<<"Codigo:     "<<al.GetCodigo_alumno()<<endl;
    char nombre [100]{};
    al.GetNombre(nombre);
    arch<<"Nombre:     "<<nombre<<endl;
}