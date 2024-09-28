/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Flota.cpp
 * Author: Enzo
 * 
 * Created on 8 de julio de 2024, 10:32 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Programacion.h"
#include "Flota.h"
#include "Vehiculo.h"
#include "Camion.h"
#include "Furgon.h"
#include "Pedido.h"


Flota::Flota() {
    
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

void Flota::cargar_vehiculos(){
    ifstream arch("vehiculos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo vehiculos.csv"<<endl;
        exit(1);
    }
    class Vehiculo *aux;
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        asignarMemoria(aux,tipo);
        aux->leer(arch);
        vehiculos[aux->GetPlaca()]=aux;
    }
}

void Flota::asignarMemoria(Vehiculo*& aux, char tipo){
    switch(tipo){
        case 'F':
            aux=new class Furgon;
            break;
        case 'C':
            aux=new class Camion;
            break;
    }
}

void Flota::mostrar_vehiculos(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    arch<<setprecision(2)<<fixed;
    string placas[5]={"A1Q-612", "D9A-711", "O8J-848", "Q5S-871", "Z4L-514"};
    arch<<setw(40)<<' '<<"REPORTE DE FLOTA"<<endl;
    for(int i=0;i<5;i++){
        vehiculos.find(placas[i])->second->mostrar(arch);
    }
}

void Flota::cargar_pedidos(){
    ifstream arch("pedidos4.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo pedidos4.csv"<<endl;
        exit(1);
    }
    string aux;
    class Pedido pedAux;
    double cargaActual;
    while(true){
        getline(arch,aux,',');
        if(arch.eof()) break;
        pedAux.leerDatos(arch);
        cargaActual=vehiculos.find(aux)->second->obtenerCargaActual();
        vehiculos.find(aux)->second->insertar(pedAux,cargaActual);
    }
}