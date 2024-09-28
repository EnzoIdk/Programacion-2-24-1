/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Revista.cpp
 * Author: margo
 * 
 * Created on 20 de junio de 2024, 7:46
 */

#include "Revista.h"

Revista::Revista() {
    ISSN=0;
    anho=0;
    numero=0;
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

void Revista::lee(ifstream&arch) {
    Libro::lee(arch);
    arch>>ISSN;
    arch.get();
    arch>>anho;
    arch.get();
    arch>>numero;
}

void Revista::actualiza() {
    if(anho<2020) vigencia=0;
}

void Revista::imprime(ofstream&arch) {
     Libro::imprime(arch);
    arch<<"ISSN: "<<ISSN<<' '<<"Anho: "<<anho<<' '<<"Vigencia: "<<vigencia<<endl;
}
