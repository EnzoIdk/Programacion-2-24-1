/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Furgon.cpp
 * Author: Enzo
 * 
 * Created on 8 de julio de 2024, 10:31 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Furgon.h"
#include "Pedido.h"
Furgon::Furgon() {
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

void Furgon::leer(ifstream& arch){
    Vehiculo::leer(arch);
    arch>>puertas;
    arch.get();
    arch>>filas;
}

void Furgon::mostrar(ofstream& arch){
    Vehiculo::mostrar(arch);
    arch<<"#Puertas: "<<setw(4)<<' '<<puertas<<endl;
    arch<<"#Filas: "<<setw(6)<<' '<<filas<<endl;
    arch<<"Lista de pedidos: "<<endl;
    if(depositos.size())
        for(class Pedido &aux:depositos){
            aux.mostrar(arch);
        }
    else
        arch<<"No hay pedidos para el cliente"<<endl;
}

void Furgon::insertar(const class Pedido& ped,double cargaActual){
    if(Vehiculo::hayEspacio(ped.GetPeso(),cargaActual)){
        insertarEnOrden(ped);
    }
}

void Furgon::insertarEnOrden(const class Pedido& ped){
    for(list<class Pedido>::iterator it=depositos.begin();it!=depositos.end();it++){
        if(*it<ped){
            depositos.insert(it,ped);
            return;
        }
    }
    //si es el menor, se inserta al final
    depositos.push_back(ped);
}

double Furgon::obtenerCargaActual(){
    double cargaActual=0;
    for(class Pedido &ped:depositos){
        cargaActual+=ped.GetPeso();
    }
    return cargaActual;
}