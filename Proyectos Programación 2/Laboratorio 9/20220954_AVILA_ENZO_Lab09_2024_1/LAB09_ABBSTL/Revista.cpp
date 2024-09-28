/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Revista.cpp
 * Author: aml
 * 
 * Created on 24 de junio de 2024, 09:48 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Revista.h"
#include "Libro.h"

Revista::Revista() {
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
    arch>>ISSN;
    arch.get();
    arch>>anho;
    arch.get();
    arch>>numero;
    arch.get();
}

void Revista::imprime(ofstream& arch){
    Libro::imprime(arch);
    arch<<"ISSN: "<<setw(8)<<ISSN<<setw(3)<<' '<<"Anho: "<<anho<<endl<<endl;
}