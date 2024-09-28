/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: Enzo
 * 
 * Created on 7 de junio de 2024, 03:50 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Alumno.h"

Alumno::Alumno() {
    nombre=nullptr;
    total=0;
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

void Alumno::lee(ifstream &arch){
    char nomb[60],car;
    arch>>codigo;
    arch.get();
    arch.getline(nomb,60,',');
    SetNombre(nomb);
    arch>>escala>>car>>creditos;
    arch.get();
}

void Alumno::imprime(ofstream &arch){
    arch<<setprecision(2)<<fixed;
    arch<<left<<setw(10)<<codigo<<setw(40)<<nombre<<right<<setw(3)<<escala<<
            setw(12)<<creditos;
}

void Alumno::actualizatotal(double pago){
    SetTotal(pago);
}

