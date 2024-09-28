/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Programacion.cpp
 * Author: Enzo
 * 
 * Created on 8 de julio de 2024, 03:28 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Programacion.h"
#include "Vehiculo.h"

Programacion::Programacion() {
}

Programacion::Programacion(const Programacion& orig) {
}

Programacion::~Programacion() {
}

void Programacion::cargavehiculos(){
    fVehiculos.cargar_vehiculos();
    fVehiculos.cargar_pedidos();
}

void Programacion::cargaprogramacion(){
    for(auto &aux:fVehiculos.vehiculos){
        PDespachos.apilar(aux.second);
    }
}

void Programacion::muestraprogramacion(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    PDespachos.imprimir(arch);
    ofstream arch2("Reporte2.txt",ios::out);
    if(not arch2.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte2.txt"<<endl;
        exit(1);
    }
    PAux.imprimir(arch2);
}

void Programacion::reducevehiculos(int cant){
    for(int i=0;i<cant;i++){
        string aux;
        PDespachos.desapilar(aux);
//        class Vehiculo *vehiculo=PDespachos.desapilar();
        PAux.apilar(fVehiculos.vehiculos.find(aux)->second);
//        PAux.apilar(vehiculo);
    }
}
