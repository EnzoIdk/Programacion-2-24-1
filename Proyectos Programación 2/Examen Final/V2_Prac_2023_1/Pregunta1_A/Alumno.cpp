/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: Jeremy Lopez Galindo
 * 
 * Created on 4 de diciembre de 2023, 06:45 PM
 */

#include "Alumno.h"

Alumno::Alumno() {
    codigo_alumno = 0;
    nombre = nullptr;
    promedio = 0;
}

//Alumno::Alumno(const Alumno& orig) {
//}

Alumno::~Alumno() {
    if(nombre)delete nombre;
}

int Alumno::getCodigoAlumno() const {
    return codigo_alumno;
}

void Alumno::getNombre(char* cad) const {
    if(nombre == nullptr)cad[0] = 0;
    else strcpy(cad,nombre);
}

double Alumno::getPromedio() const {
    return promedio;
}

void Alumno::setCodigoAlumno(int c) {
    codigo_alumno = c;
}

void Alumno::setNombre(char* cad) {
    if(nombre)delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Alumno::setPromedio(double p) {
    promedio = p;
}

void operator>>(ifstream &in,Alumno &al){
    int cod;
    char nomb[200];
    in>>cod;
    if(in.eof())return;
    in.get();
    in.getline(nomb,200);
    al.setCodigoAlumno(cod);
    al.setNombre(nomb);
}

void Alumno::imprimeAlumno(ofstream& out) {
    char nomb[200];
    getNombre(nomb);
    out<<setw(15)<<getCodigoAlumno()<<setw(50)<<nomb<<setw(10)<<getPromedio()<<endl;
}
