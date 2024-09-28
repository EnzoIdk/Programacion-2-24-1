/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Estante.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 18:58
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "Estante.h"

#define MAXLINEA 80

//CONSTRUCTOR, COPIA, DESTRUCTOR

Estante::Estante() {

}

Estante::Estante(const class Estante &orig) {
    *this=orig;
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
void Estante::operator =(const class Estante& orig){
    this->SetId(orig.GetId());
    this->SetCapacidad(orig.GetCapacidad());
    this->SetClase(orig.GetClase());
    //ASIGNAMOS LA LISTA
    Llibros=orig.Llibros;
}

void Estante::leerDatos(ifstream& arch){
    char tipoTemp;
    int idTemp;
    double capTemp;
    //V,2,10
    arch>>tipoTemp;
    arch.get();
    arch>>idTemp;
    arch.get();
    arch>>capTemp;
    arch.get();
    //GUARDAR
    this->SetId(idTemp);
    this->SetClase(tipoTemp);
    this->SetCapacidad(capTemp);
}

bool Estante::insertar(class Libro* temp){
    if(Llibros.GetPeso()+temp->GetPeso()<=capacidad){
        Llibros.insertar(temp);
        return true;
    }
    else return false;
}

void Estante::baja(int aa){
    Llibros.baja(aa);
}

void Estante::muestra(ofstream& arch){
    arch<<"Id:"<<this->GetId()<<endl;
    arch<<"Tipo: ";
    if(clase=='H') arch<<"Horizontal";
    else arch<<"Vertical";
    arch<<endl;
    arch<<"Capacidad: "<<this->GetCapacidad()<<endl;
    arch<<"Libros Contenidos:"<<endl;
    this->imprimirLinea(arch, '-');
    Llibros.muestra(arch);
}

void Estante::imprimirLinea(ofstream& arch, char car){
    for(int i=0; i<MAXLINEA; i++) arch<<car;
    arch<<endl;
}

//FUNCIONES
