/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Furgon.cpp
 * Author: margo
 * 
 * Created on 6 de julio de 2024, 17:43
 */

#include "Furgon.h"
#include <iostream>
#include <iterator>
using namespace std;

Furgon::Furgon() {
    filas=0;
    puertas=0;
}

Furgon::Furgon(const Furgon& orig) {
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

void Furgon::lee(ifstream& arch) {
    Vehiculo::lee(arch);
    arch>>filas;
    arch.get();
    arch>>puertas;
    arch.get();
}

void Furgon::imprimir(ofstream&arch) {
    if (depositos.size()==0){
        cout<<"No hay pedidods para el cliente"<<endl;
    }
    Vehiculo::imprimir(arch);
    arch<<"Filas:        "<<filas<<endl;
    arch<<"Puertas:      "<<puertas<<endl;    
    arch<<"Pedidos:"<<endl;
    for(auto x: depositos){
        x.imprime(arch);
    }
    arch<<endl;
}

void Furgon::insertar(Pedido &ped) {
     cout<<"constructor furgon"<<endl;
     list <Pedido>::iterator it;
     for(it=depositos.begin();it!=depositos.end();it++){
         if (it->GetPeso()>ped.GetPeso()) break;
     }
     depositos.insert(it,ped);
}

