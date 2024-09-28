/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Infraccion.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 02:56 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Infraccion.h"

Infraccion::Infraccion() {
    gravedad=nullptr;
}

Infraccion::Infraccion(const Infraccion& orig) {
}

Infraccion::~Infraccion() {
    if(gravedad!=nullptr) delete gravedad;
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::SetGravedad(const char *cad) {
    if(gravedad!=nullptr) delete gravedad;
    gravedad=new char[strlen(cad)+1];
    strcpy(gravedad,cad);
}

void Infraccion::GetGravedad(char *cad) const {
    if(gravedad==nullptr) cad[0]=0;
    else strcpy(cad,gravedad);
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}

void Infraccion::lee(ifstream &arch,int codInf){
    char descripcion[300],cadGrav[15];
    SetCodigo(codInf);
    arch.getline(descripcion,300,',');
    arch.getline(cadGrav,15,',');
    SetGravedad(cadGrav);
    arch>>multa;
    arch.get();
}

void Infraccion::imprime(ofstream &arch){
    arch<<left<<setw(15)<<gravedad<<right<<setw(10)<<multa;
}
