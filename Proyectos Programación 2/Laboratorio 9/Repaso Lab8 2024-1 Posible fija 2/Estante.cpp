/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Estante.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 21:19
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "Estante.h"

#define MAXLINEA 75

//CONSTRUCTOR, COPIA, DESTRUCTOR

Estante::Estante() {
    peso=0;
}

Estante::Estante(const class Estante &orig) {

}

Estante::~Estante() {

}

//GETTERS Y SETTERS
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

void Estante::SetClase(char clase) {
    this->clase = clase;
}

char Estante::GetClase() const {
    return clase;
}

//METODOS
void Estante::leer(ifstream& arch){
    char tipoTemp;
    int idTemp;
    double capTemp;
    //H,3,15
    arch>>tipoTemp;
    arch.get();
    arch>>idTemp;
    arch.get();
    arch>>capTemp;
    arch.get();
    //
    this->SetId(idTemp);
    this->SetClase(tipoTemp);
    this->SetCapacidad(capTemp);
}

void Estante::operator =(const class Estante& dato){
    this->SetId(dato.GetId());
    this->SetClase(dato.GetClase());
    this->SetCapacidad(dato.GetCapacidad());
    vlibros=dato.vlibros;
}

bool Estante::insertar(const class NLibro& libro){
    if(capacidad>=peso+libro.GetPeso()){
        vlibros.push_back(libro);
        peso+=libro.GetPeso();
        return true;
    }
    return false;
}

void Estante::baja(){
    for(int i=0; i<vlibros.size(); i++){
        vlibros[i].actualiza();
    }
}

void Estante::muestra(ofstream &arch){
    this->imprimirLinea(arch, '='); arch<<endl;
    arch<<"Id: "<<this->GetId()<<endl;
    arch<<"Tipo: ";
    if(clase=='V') arch<<"Vertical";
    else arch<<"Horizontal";
    arch<<endl;
    arch<<"Capacidad: "<<this->GetCapacidad()<<endl;
    arch<<"Libros Contenidos:"<<endl;
    this->imprimirLinea(arch, '-');
    for(int i=0; i<vlibros.size(); i++){
        vlibros[i].imprime(arch);
        arch<<endl;
    }
}

void Estante::imprimirLinea(ofstream& arch, char car){
    for(int i=0; i<MAXLINEA; i++) arch<<car;
    arch<<endl;
}

//FUNCIONES
