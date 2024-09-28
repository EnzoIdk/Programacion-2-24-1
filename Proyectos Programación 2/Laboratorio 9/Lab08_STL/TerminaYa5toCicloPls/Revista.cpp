/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Revista.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 09:13 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Revista.h"
#include "Libro.h"

Revista::Revista() {
    vigencia=1;
}

Revista::Revista(const Revista& orig) {
}

void Revista::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Revista::GetVigencia() const {
    return vigencia;
}

void Revista::SetNumero(int numero) {
    this->numero = numero;
}

int Revista::GetNumero() const {
    return numero;
}

void Revista::SetAnho(int anho) {
    this->anho = anho;
}

int Revista::GetAnho() const {
    return anho;
}

void Revista::SetISSN(int ISSN) {
    this->ISSN = ISSN;
}

int Revista::GetISSN() const {
    return ISSN;
}

void Revista::lee(ifstream& arch){
    Libro::lee(arch);
    char car;
    arch>>ISSN>>car>>anho>>car>>numero;
    arch.get();
}

void Revista::imprime(ofstream& arch){
    Libro::imprime(arch);
    arch<<"ISSN: "<<ISSN<<setw(3)<<' '<<"Anho: "<<anho<<setw(3)<<' '<<"Vigencia: "<<vigencia<<endl;
}

void Revista::actualiza(){
    if(anho>2020) vigencia=1;
    else vigencia=0;
}
