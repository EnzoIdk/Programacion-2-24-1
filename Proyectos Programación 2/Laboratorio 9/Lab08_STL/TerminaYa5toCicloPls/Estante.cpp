/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 09:36 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estante.h"
#include "Nodo.h"

Estante::Estante() {
    id=0;
    capacidad=0;
}

Estante::Estante(const Estante& orig) {
    *this=orig;
}

Estante::~Estante() {
}

void Estante::setCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double Estante::getCapacidad() const {
    return capacidad;
}

void Estante::setId(int id) {
    this->id = id;
}

int Estante::getId() const {
    return id;
}

void Estante::setClase(char clase) {
    this->clase = clase;
}

char Estante::getClase() const {
    return clase;
}

void Estante::leerDatos(ifstream& arch){
    char tipo;
    arch>>tipo;
    if(arch.eof()) return;
    arch.get();
    setClase(tipo);
    arch>>id;
    arch.get();
    arch>>capacidad;
    arch.get();
}

void Estante::imprimeEst(ofstream& arch){
    arch<<"ID: "<<id<<endl;
    arch<<"Tipo: ";
    if(clase=='H') arch<<"Horizontal"<<endl;
    else arch<<"Vertical"<<endl;
    arch<<"Capacidad: "<<capacidad<<endl;
    arch<<"Libros contenidos: "<<endl;
    Llibros.imprimeLista(arch);
}

void Estante::operator =(const Estante& orig){
    setCapacidad(orig.getCapacidad());
    setClase(orig.getClase());
    setId(orig.getId());
    Llibros=orig.Llibros;
}

int Estante::insertar(class Libro* auxLib){
    if(Llibros.getPeso()+auxLib->GetPeso()>capacidad) return 0;
    else{
        Llibros.insertar(auxLib);
        return 1;
    }
}

void Estante::actualizarEst(){
    Llibros.actualizaLista();
}

void Estante::eliminar(){
    Llibros.eliminar();
}