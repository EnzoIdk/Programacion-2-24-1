/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NLibro.cpp
 * Author: aml
 * 
 * Created on 24 de junio de 2024, 09:48 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "NLibro.h"
#include "Enciclopedia.h"
#include "Revista.h"
#include "Novela.h"

NLibro::NLibro() {
    plibro=nullptr;
}

NLibro::NLibro(const NLibro& orig) {
    this->plibro=orig.plibro;
}

NLibro::~NLibro() {
}

void NLibro::leerLib(ifstream& arch){
    char tipo;
    arch>>tipo;
    arch.get();
    switch(tipo){
        case 'N':
            plibro=new class Novela;
            break;
        case 'E':
            plibro=new class Enciclopedia;
            break;
        case 'R':
            plibro=new class Revista;
            break;
    }
    plibro->lee(arch);
}

double NLibro::obtenerPeso() const{
    return plibro->GetPeso();
}

void NLibro::imprimirLib(ofstream& arch){
    plibro->imprime(arch);
}