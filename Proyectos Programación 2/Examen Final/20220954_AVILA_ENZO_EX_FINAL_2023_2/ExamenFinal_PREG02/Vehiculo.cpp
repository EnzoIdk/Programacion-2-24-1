/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Enzo
 * 
 * Created on 8 de julio de 2024, 10:31 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    carga_actual=0;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
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

void Vehiculo::leer(ifstream& arch){
    arch>>dni;
    arch.get();
    getline(arch,placa,',');
    arch>>carga_maxima;
    arch.get();
}

void Vehiculo::mostrar(ofstream& arch){
    imprimirLinea(arch,60,'=');
    arch<<"Codigo del cliente: "<<dni<<endl;
    arch<<"Placa: "<<setw(20)<<placa<<endl;
    arch<<"Carga Maxima: "<<setw(4)<<' '<<carga_maxima<<endl;
    arch<<"Carga Actual: "<<setw(4)<<' '<<carga_actual<<endl;
    
}

void Vehiculo::imprimirLinea(ofstream& arch, int tam, char car){
    for(int i=0;i<tam;i++) arch.put(car);
    arch<<endl;
}

bool Vehiculo::hayEspacio(double peso,double totalActual){
    if(peso+totalActual<=carga_maxima){
        SetCarga_actual(peso+totalActual);
        return true;
    }
    return false;
}