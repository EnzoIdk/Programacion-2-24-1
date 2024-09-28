/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 08:06 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estante.h"

Estante::Estante() {
    id=0;
}

Estante::Estante(const Estante& orig) {
}

Estante::~Estante() {
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

void Estante::SetClase(char clase) {
    this->clase = clase;
}

char Estante::GetClase() const {
    return clase;
}

void Estante::leerEst(ifstream &arch){
    char car;
    arch>>car;
    if(arch.eof()) return;
    SetClase(car);
    arch.get();
    arch>>id;
    arch.get();
    arch>>capacidad;
}

int Estante::llenarLibro(class Libro *&libro){
    return Llibros.insertarLibro(libro,capacidad);
}

void Estante::actualizarVigencia(){
    Llibros.actualizarLista();
}

void Estante::imprimirEstante(ofstream &arch){
    imprimirLinea(arch,60,'=');
    arch<<endl<<"ID: "<<id<<endl;
    arch<<"Tipo: ";
    if(clase=='H') arch<<"Horizontal"<<endl;
    else arch<<"Vertical"<<endl;
    arch<<"Capacidad: "<<capacidad<<endl;
    arch<<"Libros contenidos: "<<endl;
    imprimirLinea(arch,60,'=');
    Llibros.imprimeLista(arch);
}

void Estante::imprimirLinea(ofstream &arch,int tam,char car){
    for(int i=0;i<tam;i++) arch.put(car);
    arch<<endl;
}