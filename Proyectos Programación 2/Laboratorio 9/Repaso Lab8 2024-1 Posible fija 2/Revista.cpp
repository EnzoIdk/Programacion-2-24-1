/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Revista.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 21:14
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Revista.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

Revista::Revista() {
    vigencia=1;
}

Revista::Revista(const class Revista &orig) {

}

Revista::~Revista() {

}

//GETTERS Y SETTERS
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

//METODOS
void Revista::lee(ifstream& arch){
    int issnTemp, numTemp, aaTemp;
    //
    this->Libro::lee(arch);
    arch>>issnTemp;
    arch.get();
    arch>>aaTemp;
    arch.get();
    arch>>numTemp;
    arch.get();
    //
    this->SetISSN(issnTemp);
    this->SetAnho(aaTemp);
    this->SetNumero(numTemp);
}

void Revista::actualiza(){
    if(anho<=2020) vigencia=0;
}

void Revista::imprime(ofstream& arch){
    this->Libro::imprime(arch);
    arch<<"ISSN: "<<this->GetISSN()<<setw(10)<<"Año: "<<this->GetAnho()<<
            setw(15)<<"Numero: "<<this->GetNumero()<<setw(15) <<"Vigencia: "<<
            this->GetVigencia()<<endl;
}

//FUNCIONES
