/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.cpp
 * Author: margo
 * 
 * Created on 20 de junio de 2024, 7:47
 */

#include "Estante.h"
#include "Biblioteca.h"
#include "Libro.h"
#include <fstream>
#include <iostream>
using namespace std;
Estante::Estante() {
    actCapacidad=0;
//    listaLibros.
}

Estante::Estante(char cl, int ide, double capa) {
    capacidad=capa;
    id=ide;
    clase=cl;
}

Estante::Estante(const Estante& orig) {
  *this=orig; 
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

void Estante::SetActCapacidad(double actCapacidad) {
    this->actCapacidad = actCapacidad;
}

double Estante::GetActCapacidad() const {
    return actCapacidad;
}

void Estante::setear(char tip, int id, double cap) {
    SetActCapacidad(0);
    SetCapacidad(cap);
    SetClase(tip);
    SetId(id);
}

void Estante::impresion() {
    cout<<actCapacidad<<' '<<capacidad<<' '<<clase<<' '<< id<<endl;
}
bool operator +=(Estante&estante, Libro *&libro){
    cout<<estante.GetActCapacidad()<<' '<<libro->GetPeso()<<' '<<estante.GetCapacidad()<<endl;
    if (estante.GetActCapacidad()+libro->GetPeso()<estante.GetCapacidad()){
        estante.insertarLista(libro);
        estante.SetActCapacidad(libro->GetPeso()+estante.GetActCapacidad());
        return true;
    }else{
        return false;
    }
}

void Estante::insertarLista( Libro*&libro) {
    listaLibros.insertarNuevoNodo(libro);
}

void Estante::operator--(int) {
    listaLibros.actualizaLibros();
}
void operator <<(ofstream &arch, Estante &est){
    est.impresionEstante(arch);
    est.impresionLibros(arch);
}

void Estante::impresionEstante(ofstream&arch) {
    arch<<"Capacidad: "<<capacidad<<endl;
    arch<<"Clase: "<<clase<<endl;
    arch<<"Id: "<<id<<endl;
}

void Estante::impresionLibros(ofstream&arch) {
    listaLibros.impresionLista(arch);
}
