/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Flota.cpp
 * Author: Lucas
 * 
 * Created on 7 de julio de 2024, 03:11 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <iterator>
using namespace std;
#include <cstring>

#include "Flota.h"
#include "Camion.h"
#include "Furgon.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
Flota::Flota() {

}

Flota::Flota(const class Flota &orig) {

}

Flota::~Flota() {

}

//GETTERS Y SETTERS

//METODOS
void Flota::cargar_vehiculos(const char * nomb){
    ifstream arch(nomb, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    class Vehiculo * temp;
    char tipo;
    //F,73786035,O4X-500,300,2,3
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get(); //,
        //
        this->asignarTipo(temp, tipo);
        temp->leer(arch);
        //GUARDAMOS
        vehiculos[temp->GetPlaca()]=temp;
    }
}

void Flota::asignarTipo(class Vehiculo * &temp, char tipo){
    switch(tipo){
        case 'F':
            temp=new class Furgon;
            break;
        case 'C':
            temp=new class Camion;
            break;
    }
}

void Flota::mostrar_vehiculos(const char * nomb){
    ofstream arch(nomb, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con el archivo: "<<nomb;
        exit(1);
    }
    arch<<fixed<<setprecision(1);
    //VEHICULOS A IMPRIMIR
    string placas[5]={"A1Q-612", "D9A-711", "O8J-848", "Q5S-871", "Z4L-514"};
    //IMPRESION
    arch<<setw(50)<<"REPORTE DE FLOTA"<<endl;
    for(int i=0; i<5; i++) vehiculos.find(placas[i])->second->mostrar(arch);
}

void Flota::cargar_pedidos(const char * nomb){
    ifstream arch(nomb, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    string placa;
    class Pedido temp;
    //I0W-872,KQQ.136,6,30
    while(true){
        getline(arch, placa, ',');
        if(arch.eof()) break;
        temp.leerDatos(arch);
        //INSERTAMOS
        vehiculos.find(placa)->second->insertar(temp);
    }
}

//FUNCIONES
