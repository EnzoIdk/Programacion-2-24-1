/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 08:05 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Enciclopedia.h"
#include "Libro.h"

Enciclopedia::Enciclopedia() {
    vigencia=1;
}

Enciclopedia::Enciclopedia(const Enciclopedia& orig) {
}

Enciclopedia::~Enciclopedia() {
}

void Enciclopedia::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Enciclopedia::GetVigencia() const {
    return vigencia;
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

void Enciclopedia::lee(ifstream &arch){
    Libro::lee(arch);
    arch>>sku;
    arch.get();
    arch>>anho;
//    if(anho<2024) vigencia=0; aca no va
} 

void Enciclopedia::actualiza(){
    if(anho<=2020) vigencia=0;
}

void Enciclopedia::imprime(ofstream &arch){
    Libro::imprime(arch);
    arch<<"SKU:"<<setw(8)<<sku<<setw(3)<<' '<<"Anho:"<<setw(6)<<anho<<
            setw(4)<<' '<<"Vigencia: "<<vigencia<<endl<<endl;
}