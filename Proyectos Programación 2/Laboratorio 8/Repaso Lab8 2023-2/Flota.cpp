/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Flota.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 12:52 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Flota.h"

Flota::Flota() {
}

Flota::~Flota() {
    //ELIMINAR LISTA?
}

void Flota::cargaFlota(const char * nomb){
    ifstream arch(nomb, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    lista.crear(arch);
}

void Flota::muestraCarga(const char * nomb){
    ofstream arch(nomb, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    arch<<fixed<<setprecision(2);
    lista.imprime(arch);
}

void Flota::cargaPedidos(const char * nomb){
    ifstream arch(nomb, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    lista.actualizar(arch);
}
