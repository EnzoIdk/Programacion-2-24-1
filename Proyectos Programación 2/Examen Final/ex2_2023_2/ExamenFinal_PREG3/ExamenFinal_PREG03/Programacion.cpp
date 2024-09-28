/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programacion.cpp
 * Author: margo
 * 
 * Created on 7 de julio de 2024, 13:22
 */

#include "Programacion.h"
#include <iostream>
using namespace std;
Programacion::Programacion() {
}

Programacion::Programacion(const Programacion& orig) {
}

Programacion::~Programacion() {
}

void Programacion::cargavehiculos() {
    fVehiculos.cargar_vehiculos();
    fVehiculos.cargar_pedidos();
    fVehiculos.mostrar_vehiculos();
    
}

void Programacion::cargaprogramacion() {
    for(auto &x : fVehiculos.vehiculos){
        Vehiculo *ptr= x.second;
        if (ptr!=nullptr) {
            cout<<"se inserta nodo"<<endl;
            ADespachos.insertarNodo(ptr);
        }else{
            
            cout<<"no se inserta nodo"<<endl;
        }
    }
}

void Programacion::reducevehiculos(int cant) {
    ADespachos.reducirVehiculos(cant);
}

void Programacion::muestraprogramacion() {
    ofstream arch("mostrarProgramacion.txt", ios::out);
    if (not arch.is_open()){
        cout<<"error con la impresion mostrar Programacion "<<endl;
        exit(1);
    }
     ADespachos.muestraprogramacion(arch);
}

