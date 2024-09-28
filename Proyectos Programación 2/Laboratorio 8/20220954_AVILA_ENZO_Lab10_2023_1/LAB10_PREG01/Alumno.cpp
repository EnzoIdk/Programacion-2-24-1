/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: Enzo
 * 
 * Created on 10 de junio de 2024, 10:22 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Alumno.h"

Alumno::Alumno() {
    nombre=nullptr;
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

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
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

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::lee(ifstream &arch){
    char nomb[60],car;
    arch>>codigo;
    arch.get();
    arch.getline(nomb,60,',');
    SetNombre(nomb);
    arch>>escala>>car>>creditos>>car;
}

void Alumno::imprime(ofstream &arch){
    arch<<fixed<<setprecision(2);
    arch<<left<<setw(10)<<codigo<<setw(40)<<nombre<<right<<setw(3)<<escala<<
            setw(12)<<creditos;
}