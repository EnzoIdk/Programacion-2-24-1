/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Revista.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 08:06 AM
 */

#include <iomanip>
#include <iostream>
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

Revista::~Revista() {
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

void Revista::lee(ifstream &arch){
    Libro::lee(arch);
    arch>>ISSN;
    arch.get();
    arch>>anho;
    arch.get();
    arch>>numero;
}

void Revista::actualiza(){
    if(anho<=2020) vigencia=0;
}

void Revista::imprime(ofstream &arch){
    Libro::imprime(arch);
    arch<<"ISSN:"<<setw(8)<<ISSN<<setw(3)<<' '<<"Anho:"<<setw(6)<<anho<<
            setw(4)<<' '<<"Vigencia: "<<vigencia<<setw(5)<<' '<<
            "Numero: "<<numero<<endl<<endl;
}