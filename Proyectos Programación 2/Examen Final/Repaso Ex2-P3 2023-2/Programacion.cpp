/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Programacion.cpp
 * Author: Lucas
 * 
 * Created on 7 de julio de 2024, 07:22 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Programacion.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
Programacion::Programacion() {

}

Programacion::Programacion(const class Programacion &orig) {

}

Programacion::~Programacion() {

}

//GETTERS Y SETTERS

//METODOS
void Programacion::cargavehiculos(){
    fvehiculos.cargar_vehiculos("Vehiculos.csv");
    fvehiculos.cargar_pedidos("Pedidos4.csv");
}

void Programacion::cargaprogramacion(){
    for(auto dato:fvehiculos.vehiculos) ADespachos.insertar(dato.second);
}

void Programacion::reducevehiculos(int cantidad){
    ADespachos.eliminarNodo(cantidad);
}

void Programacion::muestraprogramacion(){
    ofstream arch("Reporte.txt", ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: Reporte.txt";
        exit(1);
    }
    arch<<fixed<<setprecision(1);
    arch<<setw(50)<<"REPORTE DE FLOTA"<<endl;
    ADespachos.recorrerEnOrden(arch);
}

//FUNCIONES
