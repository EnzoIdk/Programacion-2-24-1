/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Camion.cpp
 * Author: Enzo
 * 
 * Created on 8 de julio de 2024, 10:31 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Camion.h"
#include "Pedido.h"

Camion::Camion() {
}

Camion::Camion(const Camion& orig) {
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

void Camion::leer(ifstream& arch){
    Vehiculo::leer(arch);
    arch>>ejes;
    arch.get();
    arch>>llantas;
}

void Camion::mostrar(ofstream& arch){
    Vehiculo::mostrar(arch);
    arch<<"#Llantas: "<<setw(5)<<' '<<llantas<<endl;
    arch<<"#Ejes: "<<setw(10)<<' '<<ejes<<endl;
    arch<<"Lista de pedidos: "<<endl;
    if(depositos.size())
        for(class Pedido &aux:depositos){
            aux.mostrar(arch);
        }
    else
        arch<<"No hay pedidos para el cliente"<<endl;
}

void Camion::insertar(const class Pedido& ped,double cargaActual){
    if(depositos.size()<5){
        if(Vehiculo::hayEspacio(ped.GetPeso(),cargaActual))
            depositos.push_back(ped);
    }
}

double Camion::obtenerCargaActual(){
    double cargaActual=0;
    for(class Pedido &aux:depositos){
        cargaActual+=aux.GetPeso();
    }
    return cargaActual;
}

char Camion::getTipo() const{
    return 'C';
}