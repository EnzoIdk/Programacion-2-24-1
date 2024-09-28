/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.cpp
 * Author: margo
 * 
 * Created on 6 de julio de 2024, 17:42
 */

#include "Vehiculo.h"
#include <iostream>
using namespace std;

Vehiculo::Vehiculo() {
    dni=0;
    carga_actual=0;
    carga_maxima=0;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
    this->placa=orig.placa;
    this->carga_actual=orig.carga_actual;
    this->carga_maxima=orig.carga_maxima;
    this->dni=orig.dni;
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::SetCarga_actual(double carga_actual) {
    this->carga_actual = carga_actual;
}

double Vehiculo::GetCarga_actual() const {
    return carga_actual;
}

void Vehiculo::SetCarga_maxima(double carga_maxima) {
    this->carga_maxima = carga_maxima;
}

double Vehiculo::GetCarga_maxima() const {
    return carga_maxima;
}

void Vehiculo::SetPlaca(string placa) {
    this->placa = placa;
}

string Vehiculo::GetPlaca() const {
    return placa;
}

void Vehiculo::SetDni(int dni) {
    this->dni = dni;
}

int Vehiculo::GetDni() const {
    return dni;
}

void Vehiculo::lee(ifstream& arch) {
    arch>>dni;
    arch.get();
    getline(arch,placa,',');
    arch>>carga_maxima;
    arch.get();
    
}


void Vehiculo::operator=(const Vehiculo&veh) {
    cout<<"operador ="<<endl;
    this->placa=veh.placa;
    this->carga_actual=veh.carga_actual;
    this->carga_maxima=veh.carga_maxima;
    this->dni=veh.dni;
}

void Vehiculo::imprimir(ofstream&arch) {
    arch<<"DNI:          "<<dni<<endl;
    arch<<"Placa:        "<<placa<<endl;
    arch<<"Carga maxima: "<<carga_maxima<<endl;
   
}
