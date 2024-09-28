/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Lucas
 * 
 * Created on 7 de julio de 2024, 01:53 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
#include <cstring>

#include "Vehiculo.h"

#define MAXLINEA 80

//CONSTRUCTOR, COPIA, DESTRUCTOR
Vehiculo::Vehiculo() {
    carga_actual=0;
}

Vehiculo::Vehiculo(const class Vehiculo &orig) {

}

Vehiculo::~Vehiculo() {

}

//GETTERS Y SETTERS
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

//METODOS
void Vehiculo::leer(ifstream &arch){
    string placaTemp;
    int dniTemp;
    double cargaTemp;
    //LECTURA
    arch>>dniTemp;
    arch.get(); //,
    getline(arch, placaTemp, ',');
    arch>>cargaTemp;
    arch.get(); //,
    //GUARDAR
    this->SetDni(dniTemp);
    this->SetPlaca(placaTemp);
    this->SetCarga_maxima(cargaTemp);
}

void Vehiculo::mostrar(ofstream &arch){
    this->imprimirLinea(arch, '=');
    arch<<left;
    arch<<setw(20)<<"Codigo de Cliente:"<<this->GetDni()<<endl;
    arch<<setw(20)<<"Placa:"<<this->GetPlaca()<<endl;
    arch<<setw(20)<<"Carga Maxima:"<<this->GetCarga_maxima()<<endl;
    arch<<setw(20)<<"Carga Actual:"<<this->GetCarga_actual()<<endl;
}

void Vehiculo::imprimirLinea(ofstream &arch, char car){
    for(int i=0; i<MAXLINEA; i++) arch<<car;
    arch<<endl;
}

bool Vehiculo::hayEspacio(double peso){
    if(peso+carga_actual<=carga_maxima){
        carga_actual+=peso;
        return true;
    }
    else return false;
}
//FUNCIONES
