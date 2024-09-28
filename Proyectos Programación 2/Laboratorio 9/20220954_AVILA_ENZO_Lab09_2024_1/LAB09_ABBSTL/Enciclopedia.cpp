/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: aml
 * 
 * Created on 24 de junio de 2024, 09:47 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Enciclopedia.h"
#include "Libro.h"

Enciclopedia::Enciclopedia() {
}

void Enciclopedia::SetAnho(int anho) {
    this->anho = anho;
}

int Enciclopedia::GetAnho() const {
    return anho;
}

void Enciclopedia::SetSku(int sku) {
    this->sku = sku;
}

int Enciclopedia::GetSku() const {
    return sku;
}

void Enciclopedia::lee(ifstream& arch){
    Libro::lee(arch);
    arch>>sku;
    arch.get();
    arch>>anho;
    arch.get();
}

void Enciclopedia::imprime(ofstream& arch){
    Libro::imprime(arch);
    arch<<"SKU: "<<setw(6)<<sku<<setw(3)<<' '<<"Anho: "<<anho<<endl<<endl;
}
