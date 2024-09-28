/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Furgon.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 12:41 PM
 */

#include <iomanip>
using namespace std;
#include "Furgon.h"

Furgon::Furgon() {
}

Furgon::~Furgon() {
}


void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}


void Furgon::lee(ifstream &arch){
    this->Vehiculo::lee(arch);
    //CONTINUAMOS LA LECTURA
    arch>>puertas;
    arch.get();
    arch>>filas;
    arch.get();//\n
}

void Furgon::imprime(ofstream &arch){
    this->Vehiculo::imprime(arch);
    //
    arch<<"#Filas:"<<setw(10)<<filas<<endl;
    arch<<"#Puertas:"<<setw(10)<<puertas<<endl;
    arch<<setw(20)<<"PEDIDOS:"<<endl;
    this->Vehiculo::imprimePedidos(arch);
    arch<<endl;
}