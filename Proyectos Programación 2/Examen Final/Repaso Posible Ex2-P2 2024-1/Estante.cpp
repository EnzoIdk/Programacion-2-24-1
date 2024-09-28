/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Estante.cpp
 * Author: Lucas
 * 
 * Created on 8 de julio de 2024, 07:53 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Estante.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

Estante::Estante() {

}

Estante::Estante(const class Estante &orig) {
    *this=orig;
}

Estante::~Estante() {

}

//GETTERS Y SETTERS
void Estante::SetDisponible(double disponible) {
    this->disponible = disponible;
}

double Estante::GetDisponible() const {
    return disponible;
}

void Estante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double Estante::GetCapacidad() const {
    return capacidad;
}

void Estante::SetId(int id) {
    this->id = id;
}

int Estante::GetId() const {
    return id;
}

//METODOS
void Estante::operator =(const class Estante &orig){
    id=orig.GetId();
    capacidad=orig.GetCapacidad();
    disponible=orig.GetDisponible();
}

bool Estante::operator ==(const class Estante &orig) const{
    return id==orig.GetId();
}

bool Estante::operator <(const class Estante &orig) const{
    return id<orig.GetId();
}

void Estante::leer(ifstream &arch){
    int idTemp;
    double capTemp;
    //LECTURA
    arch>>idTemp;
    if(arch.eof()) return;
    arch.get();
    arch>>capTemp;
    //GUARDAMOS
    this->SetId(idTemp);
    this->SetCapacidad(capTemp);
    this->SetDisponible(capTemp);
}

void Estante::actualizar(double peso){
    disponible-=peso;
}

void Estante::imprimir(ofstream &arch) const{
    arch<<"Id: "<<this->GetId()<<endl;
    arch<<"Capacidad: "<<this->GetCapacidad()<<setw(15)<<"Disponible: "<<
            this->GetDisponible()<<endl;
}

//FUNCIONES
