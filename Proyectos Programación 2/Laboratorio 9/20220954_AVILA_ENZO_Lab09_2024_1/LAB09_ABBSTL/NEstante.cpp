/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NEstante.cpp
 * Author: aml
 * 
 * Created on 24 de junio de 2024, 09:48 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "NEstante.h"
#include "NLibro.h"
NEstante::NEstante() {
    izq=nullptr;
    der=nullptr;
    capacidad=0;
    disponible=0;
    id=0;
}

//NEstante::NEstante(const NEstante& orig) {
//}
//
//NEstante::~NEstante() {
//}

void NEstante::SetDisponible(double disponible) {
    this->disponible = disponible;
}

double NEstante::GetDisponible() const {
    return disponible;
}

void NEstante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double NEstante::GetCapacidad() const {
    return capacidad;
}

void NEstante::SetId(int id) {
    this->id = id;
}

int NEstante::GetId() const {
    return id;
}

void NEstante::leerEst(ifstream& arch){
    int aux;
    arch>>aux;
    if(arch.eof()) return;
    SetId(aux);
    arch.get();
    arch>>capacidad;
    SetDisponible(capacidad);
    arch.get();
}

void NEstante::agregarAEst(NLibro& auxLib){
    vlibros.push_back(auxLib);
    SetDisponible(GetDisponible()-auxLib.obtenerPeso());
}

void NEstante::imprimirEst(ofstream& arch){
    arch<<"Estante: "<<id<<endl;
    arch<<"Capacidad: "<<setw(6)<<capacidad<<setw(3)<<' '<<"Disponible: "<<
            setw(6)<<disponible<<endl;
    imprimirLinea(arch,70,'=');
    for(int i=0;i<vlibros.size();i++){
        vlibros[i].imprimirLib(arch);
    }
    arch<<endl;
}

void NEstante::imprimirLinea(ofstream& arch, int tam, int simb){
    for(int i=0;i<tam;i++) arch.put(simb);
    arch<<endl;
}