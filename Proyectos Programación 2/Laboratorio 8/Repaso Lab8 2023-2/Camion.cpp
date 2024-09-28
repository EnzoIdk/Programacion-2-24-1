/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Camion.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 12:25 PM
 */

#include <iomanip>
using namespace std;
#include "Camion.h"

Camion::Camion() {
}

Camion::~Camion() {
}


void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

void Camion::lee(ifstream &arch){
    this->Vehiculo::lee(arch);
    //CONTINUAMOS LA LECTURA
    arch>>ejes;
    arch.get();
    arch>>llantas;
    arch.get();//\n;
}

void Camion::imprime(ofstream &arch){
    this->Vehiculo::imprime(arch);
    //
    arch<<"#Ejes:"<<setw(10)<<ejes<<endl;
    arch<<"#LLantas:"<<setw(10)<<llantas<<endl;
    arch<<setw(20)<<"PEDIDOS:"<<endl;
    this->Vehiculo::imprimePedidos(arch);
    arch<<endl;
}