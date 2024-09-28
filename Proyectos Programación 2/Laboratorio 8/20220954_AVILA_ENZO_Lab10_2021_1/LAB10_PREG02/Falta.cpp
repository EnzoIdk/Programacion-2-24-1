/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Falta.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 03:08 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Falta.h"

Falta::Falta() {
    placa=nullptr;
}

Falta::~Falta() {
    if(placa!=nullptr) delete placa;
}

void Falta::SetPlaca(const char *cad) {
    if(placa!=nullptr) delete placa;
    placa=new char[strlen(cad)+1];
    strcpy(placa,cad);
}

void Falta::GetPlaca(char *cad) const {
    if(placa==nullptr) cad[0]=0;
    else strcpy(cad,placa);
}

void Falta::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Falta::GetFecha() const {
    return fecha;
}

void Falta::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Falta::GetLicencia() const {
    return licencia;
}

void Falta::leerDatos(ifstream &arch,int &codInf){
    char cad[10],car;
    int dd,mm,aa;
    arch>>licencia;
    if(arch.eof()) return;
    arch.get();
    arch.getline(cad,10,',');
    SetPlaca(cad);
    arch>>dd>>car>>mm>>car>>aa>>car>>codInf;
    fecha=aa*10000+mm*100+dd;
}

void Falta::operator =(const class Falta &orig){
    char cad[10];
    fecha=orig.GetFecha();
    licencia=orig.GetLicencia();
    orig.GetPlaca(cad);
    SetPlaca(cad);
}

void Falta::imprimeF(ofstream &arch){
    imprimeFecha(arch);
    arch<<setw(12)<<licencia<<setw(3)<<' '<<left<<setw(12)<<placa<<right;
}

void Falta::imprimeFecha(ofstream &arch){
    int aa=fecha/10000;
    int mm=(fecha/100)%100;
    int dd=fecha%100;
    arch<<setfill('0')<<aa<<'/'<<setw(2)<<mm<<'/'<<setw(2)<<dd<<setfill(' ');
}