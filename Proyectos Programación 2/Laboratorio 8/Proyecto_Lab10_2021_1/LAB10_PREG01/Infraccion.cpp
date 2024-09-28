/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.cpp
 * Author: ISA
 * 
 * Created on 6 de junio de 2024, 03:40 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Infraccion.h"

Infraccion::Infraccion() {
    codigo = 0;
    gravedad = nullptr;
    multa = 0.0;
}

Infraccion::Infraccion(const Infraccion& orig) {
}

Infraccion::~Infraccion() {
    if(gravedad != nullptr)delete gravedad;
}
void Infraccion::operator = (const Infraccion& orig){
    codigo = orig.codigo;
    multa = orig.multa;
    SetGravedad(orig.gravedad);
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}

void Infraccion::SetGravedad(char *cad){
    if(gravedad != nullptr)delete gravedad;
    gravedad = new char[strlen(cad)+1];
    strcpy(gravedad,cad);
}
void Infraccion::GetGravedad(char *cad) const{
    if(gravedad != nullptr)
        strcpy(cad,gravedad);
}

bool Infraccion::lee(ifstream &arch,int cod){
    char cadena[300];
    while(true){
        arch >> codigo;
        if(arch.eof())return false;
        if(codigo == cod){
            arch.get();
            arch.getline(cadena,300,',');
            arch.getline(cadena,25,',');
            SetGravedad(cadena);
            arch >> multa;
            arch.get();
            break;
        }else while(arch.get()!='\n');
    }
    return true;
}

void Infraccion::imprime(ofstream &arch){
    arch << left << setw(16) << gravedad << setw(10) << multa;
}