/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 09:01 PM
 */

#include <iostream>
#include <iomanip>
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

void Enciclopedia::lee(ifstream& arch){
    Libro::lee(arch);
    arch>>sku;
    arch.get();
    arch>>anho;
    arch.get();
}

void Enciclopedia::imprime(ofstream& arch){
    Libro::imprime(arch);
    arch<<"SKU: "<<setw(7)<<sku<<setw(3)<<' '<<"Anho: "<<setw(5)<<anho<<
            setw(5)<<' '<<"Vigencia: "<<vigencia<<endl;
}

void Enciclopedia::actualiza(){
    if(anho>2020) vigencia=1;
    else vigencia=0;
}