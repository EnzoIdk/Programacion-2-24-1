/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: Enzo
 * 
 * Created on 13 de junio de 2024, 08:23 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>   
#include <cstring>
using namespace std;
#include "Libro.h"
#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
    peso=0;
}

void Enciclopedia::SetPeso(double peso) {
    this->peso = peso;
}

double Enciclopedia::GetPeso() const {
    return peso;
}

void Enciclopedia::SetVolumen(int volumen) {
    this->volumen = volumen;
}

int Enciclopedia::GetVolumen() const {
    return volumen;
}

void Enciclopedia::leerLib(ifstream &arch){
    Libro::leerLib(arch);
    arch>>volumen;
    arch.get();
    arch>>peso;
    arch.get();
    Libro::SetPeso(peso);
}

void Enciclopedia::imprimirLib(ofstream &arch){
    Libro::SetPeso(peso);
    Libro::imprimirLib(arch);
    arch<<setw(5)<<volumen<<endl;
}