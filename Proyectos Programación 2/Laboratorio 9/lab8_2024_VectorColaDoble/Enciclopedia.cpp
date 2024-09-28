/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: margo
 * 
 * Created on 20 de junio de 2024, 7:41
 */

#include "Enciclopedia.h"
#include <cstring >
using namespace std;
Enciclopedia::Enciclopedia() {
    anho=0;
    sku=0;
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

void Enciclopedia::lee(ifstream&arch) {
    Libro::lee(arch);
    arch>>sku;
    arch.get();
    arch>>anho;
}

void Enciclopedia::actualiza() {
    if (anho<2020) vigencia=0;
}

void Enciclopedia::imprime(ofstream&arch) {
    Libro::imprime(arch);
    arch<<"Sku: "<<sku<<' '<<"Anho: "<<anho<<' '<<"Vigencia: "<<vigencia<<endl;
}
