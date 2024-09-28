/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Camion.cpp
 * Author: Lucas
 * 
 * Created on 7 de julio de 2024, 01:55 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Camion.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
Camion::Camion() {

}

Camion::Camion(const class Camion &orig) {

}

Camion::~Camion() {

}

//GETTERS Y SETTERS
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

//METODOS
void Camion::leer(ifstream &arch){
    int llantasTemp, ejesTemp;
    //LECTURA
    this->Vehiculo::leer(arch);
    arch>>ejesTemp;
    arch.get(); //,
    arch>>llantasTemp;
    arch.get(); //\n
    //GUARDAR
    this->SetLlantas(llantasTemp);
    this->SetEjes(ejesTemp);
}

void Camion::mostrar(ofstream &arch){
    this->Vehiculo::mostrar(arch);
    arch<<setw(20)<<"#Llantas:"<<this->GetLlantas()<<endl;
    arch<<setw(20)<<"#Ejes:"<<this->GetEjes()<<endl;
    //PEDIDOS
    arch<<"Lista de Pedidos:"<<endl;
    if(depositos.size()) for(class Pedido &dato:depositos) dato.mostrar(arch);
    else arch<<"No hay pedidos para el cliente"<<endl;
}

void Camion::insertar(const class Pedido &pedido){
    if(depositos.size()<5){
        if(this->Vehiculo::hayEspacio(pedido.GetPeso()))
            depositos.push_back(pedido);
    }
}

//FUNCIONES
