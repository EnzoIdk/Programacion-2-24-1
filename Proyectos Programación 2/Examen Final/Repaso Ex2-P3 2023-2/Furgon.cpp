/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Furgon.cpp
 * Author: Lucas
 * 
 * Created on 7 de julio de 2024, 02:25 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Furgon.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
Furgon::Furgon() {

}

Furgon::Furgon(const class Furgon &orig) {

}

Furgon::~Furgon() {

}

//GETTERS Y SETTERS
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

//METODOS
void Furgon::leer(ifstream &arch){
    int puertasTemp, filasTemp;
    //LECTURA
    this->Vehiculo::leer(arch);
    arch>>puertasTemp;
    arch.get(); //,
    arch>>filasTemp;
    arch.get(); //\n
    //GUARDAR
    this->SetPuertas(puertasTemp);
    this->SetFilas(filasTemp);
}

void Furgon::mostrar(ofstream &arch){
    this->Vehiculo::mostrar(arch);
    arch<<setw(20)<<"#Puertas:"<<this->GetPuertas()<<endl;
    arch<<setw(20)<<"#Filas:"<<this->GetFilas()<<endl;
    //PEDIDOS
    arch<<"Lista de Pedidos:"<<endl;
    if(depositos.size()) for(class Pedido &dato:depositos) dato.mostrar(arch);
    else arch<<"No hay pedidos para el cliente"<<endl;
}

void Furgon::insertar(const class Pedido &pedido){
    if(this->Vehiculo::hayEspacio(pedido.GetPeso())){
        this->insertarEnOrden(pedido);
    }
}

void Furgon::insertarEnOrden(const class Pedido &pedido){
    list<class Pedido>::iterator aux=depositos.begin();
    //RECORRIDO
    while(aux!=depositos.end()){
        if(*aux<pedido) break;
        else aux++;
    }
    //SI LLEGO HASTA EL FINAL DEL RECORRIDO (TIENE EL MENOR PESO)
    if(aux==depositos.end()) depositos.push_back(pedido);
    else depositos.insert(aux, pedido);
}
//FUNCIONES
