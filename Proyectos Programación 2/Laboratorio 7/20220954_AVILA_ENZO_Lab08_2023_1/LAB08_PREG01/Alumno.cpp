/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: Enzo
 * 
 * Created on 28 de mayo de 2024, 12:14 AM
 */

#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
#include "Alumno.h"

Alumno::Alumno() {
    nombre=nullptr;
    codigo=0;
    total=0.0;
}

Alumno::~Alumno() {
    if(nombre!=nullptr) delete nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char *nomb) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Alumno::GetNombre(char *nomb) const {
    if(nombre==nullptr) nomb[0]=0;
    else strcpy(nomb,nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

/*esta lectura se repite para todos*/
void Alumno::leerDatos(ifstream &arch){
    char nomb[60];
    arch>>codigo;
    if(arch.eof()) return;
    arch.get();
    arch.getline(nomb,60,',');
    SetNombre(nomb);
    arch>>escala;
    arch.get();
}

void Alumno::imprime(ofstream &arch){
    arch<<left<<setw(10)<<codigo<<setw(40)<<nombre<<right<<setw(3)<<escala;
}