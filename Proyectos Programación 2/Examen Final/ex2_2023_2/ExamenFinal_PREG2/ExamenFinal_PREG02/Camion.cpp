/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camion.cpp
 * Author: margo
 * 
 * Created on 6 de julio de 2024, 20:28
 */

#include "Camion.h"
#include <iostream>
using namespace std;
Camion::Camion() {
    ejes=0;
    llantas;
    carga_actual=0;
}

Camion::Camion(const Camion& orig) {
}

Camion::~Camion() {
}

void Camion::SetCarga_actual(double carga_actual) {
    this->carga_actual = carga_actual;
}

double Camion::GetCarga_actual() const {
    return carga_actual;
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

void Camion::lee(ifstream&arch) {
    Vehiculo::lee(arch);
    arch>>ejes;
    arch.get();
    arch>>llantas;
}

void Camion::imprimir(ofstream&arch) {
     if (depositos.size()==0){
        cout<<"No hay pedidods para el cliente"<<endl;
    }
    Vehiculo::imprimir(arch);
    arch<<"Ejes: "<<ejes<<endl;
    arch<<"Llantas: "<<llantas<<endl;
    arch<<"Pedidos: "<<endl;
    for(auto x: depositos){
        x.imprime(arch);
    }
}

void Camion::insertar(Pedido &ped) {
    cout<<"constructor camion"<<endl;
    if (depositos.size()<5){
         Vehiculo::SetCarga_actual(ped.GetPeso()+Vehiculo::GetCarga_actual());
        depositos.push_back(ped);
    }
}
