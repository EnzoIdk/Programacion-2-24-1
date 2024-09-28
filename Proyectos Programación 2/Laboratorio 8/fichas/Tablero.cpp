/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.cpp
 * Author: margo
 * 
 * Created on 11 de junio de 2024, 18:30
 */

#include "Tablero.h"
#include "FIchas.h"
#include <fstream>
#include <iostream>
using namespace std;

Tablero::Tablero() {
    
}

Tablero::Tablero(const Tablero& orig) {
}

Tablero::~Tablero() {
}

void Tablero::lecturaIncial(const char* nombarch) {
    ifstream arch(nombarch, ios::in);
    if (not arch.is_open()){
        cout<<"error con la apertura "<<endl;
        exit(1);
    }
    //F1      C      8      15
    listaPosiciones.lecturaFichar(arch);
}

void Tablero::impresion(const char* nombarch) {
     ofstream arch(nombarch, ios::out);
    if (not arch.is_open()){
        cout<<"error con la apertura "<<endl;
        exit(1);
    }
     listaPosiciones.imprimeLista(arch);
}

void Tablero::movimientos(const char* nombarch) {
     ifstream arch(nombarch, ios::in);
    if (not arch.is_open()){
        cout<<"error con la apertura "<<endl;
        exit(1);
    }
     listaPosiciones.actualizar(arch);
}

