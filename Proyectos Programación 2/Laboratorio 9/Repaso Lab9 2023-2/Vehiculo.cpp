/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 12:13
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Vehiculo.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

Vehiculo::Vehiculo() {
    placa=nullptr;
    actcarga=0;
}

Vehiculo::Vehiculo(const class Vehiculo &orig) {

}

Vehiculo::~Vehiculo() {
    if(placa!=nullptr) delete placa;
}

//GETTERS Y SETTERS
void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(char* cad) {
    if(placa!=nullptr) delete placa;
    placa=new char[strlen(cad)+1];
    strcpy(placa, cad);
}

void Vehiculo::GetPlaca(char * cad) const {
    if(placa==nullptr) cad[0]=0;
    else strcpy(cad, placa);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

//METODOS
void Vehiculo::lee(ifstream& arch){
    int cliTemp;
    char placaTemp[10];
    double maxTemp;
    //20864087,O5L-856,1000,2,6
    arch>>cliTemp;
    arch.get();
    arch.getline(placaTemp, 10, ',');
    arch>>maxTemp;
    arch.get();
    //GUARDAR
    this->SetCliente(cliTemp);
    this->SetPlaca(placaTemp);
    this->SetMaxcarga(maxTemp);
}

void Vehiculo::imprime(ofstream& arch){
    char placaTemp[10];
    this->GetPlaca(placaTemp);
    //
    arch<<left<<setw(16)<<"Codigo Cliente:"<<right<<this->GetCliente()<<endl;
    arch<<left<<setw(16)<<"Placa:"<<right<<placaTemp<<endl;
    arch<<left<<setw(16)<<"Carga Maxima:"<<right<<this->GetMaxcarga()<<endl;
    arch<<left<<setw(16)<<"Carga Actual:"<<right<<this->GetActcarga()<<endl;
}

//FUNCIONES
