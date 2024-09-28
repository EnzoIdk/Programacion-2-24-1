/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   LVehiculos.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 12:48 PM
 */

#include <iomanip>
using namespace std;
#include "LVehiculos.h"
#include "NodoLista.h"
#include "Furgon.h"
#include "Camion.h"

#define MAXLINEA 80

LVehiculos::LVehiculos() {
    lini=nullptr;
    lfin=nullptr;
}

LVehiculos::~LVehiculos() {
    //ELIMINA LISTA
}


void LVehiculos::crear(ifstream &arch){
    class Vehiculo * vehiculoTemp;
    char tipo;
    //C,94326707,U3F-754,1000,2,8
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        //ASIGNAMOS LOS DATOS
        this->asignarMemoria(vehiculoTemp, tipo);
        vehiculoTemp->lee(arch);
        this->insertar(vehiculoTemp);
    }
}

void LVehiculos::asignarMemoria(class Vehiculo * &vehiculo, char tipo){
    switch(tipo){
        case 'F':
            vehiculo=new class Furgon;
            break;
        case 'C':
            vehiculo=new class Camion;
            break;
    }
}


void LVehiculos::insertar(class Vehiculo * vehiculo){
    class NodoLista * nuevo=new class NodoLista;
    nuevo->unidad=vehiculo;
    if(lini==nullptr){
        lini=nuevo;
        lfin=nuevo;
    }
    else{
        lfin->sig=nuevo;
        lfin=nuevo;
    }
}

void LVehiculos::imprime(ofstream &arch){
    class NodoLista * aux=lini;
    arch<<setw(40)<<"REPORTE DE FLOTA"<<endl;
    arch<<setfill('=')<<setw(MAXLINEA)<<'-'<<setfill(' ')<<endl<<endl;
    while(aux){
        aux->unidad->imprime(arch);
        arch<<setfill('-')<<setw(MAXLINEA)<<'-'<<setfill(' ')<<endl;
        aux=aux->sig;
    }
}

void LVehiculos::actualizar(ifstream &arch){
    int codTemp, cantTemp;
    double pesoTemp;
    char idPed[10];
    //20864087,AWB.345,1,3
    while(true){
        arch>>codTemp;
        if(arch.eof()) break;
        arch.get();
        arch.getline(idPed, 10, ',');
        arch>>cantTemp;
        arch.get();
        arch>>pesoTemp;
        //GUARDAR
        this->crearPedido(codTemp, idPed, cantTemp, pesoTemp);
    }
}

void LVehiculos::crearPedido(int codTemp, char* idPed, int cantTemp, 
        double pesoTemp){
    class NodoLista * aux=lini;
    //BUSCAMOS
    while(aux){
        if(aux->unidad->GetCliente()==codTemp){
            aux->unidad->crearPedido(idPed, cantTemp, pesoTemp);
            break;
        }
        aux=aux->sig;
    }
}