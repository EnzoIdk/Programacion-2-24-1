/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Revista.cpp
 * Author: Lucas
 * 
 * Created on 8 de julio de 2024, 07:48 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Revista.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
Revista::Revista() {
    vigente=true;
}

Revista::Revista(const class Revista &orig) {

}

Revista::~Revista() {

}

//GETTERS Y SETTERS
void Revista::SetVigente(bool vigente) {
    this->vigente = vigente;
}

bool Revista::IsVigente() const {
    return vigente;
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
void Revista::leer(ifstream &arch){
    int issnTemp, aaTemp, numTemp;
    //R,Educacion,48,0.2,10199403,2024,6
    this->Libro::leer(arch);
    //78323,2015
    arch>>issnTemp;
    arch.get(); //,
    arch>>aaTemp;
    arch.get(); //,
    arch>>numTemp;
    arch.get();//\n
    //GUARDAMOS
    this->SetAnho(aaTemp);
    this->SetISSN(issnTemp);
    this->SetNumero(numTemp);
}

void Revista::imprimir(ofstream &arch){
    this->Libro::imprimir(arch);
    arch<<"ISSN: "<<this->GetISSN()<<setw(10)<<"Año: "<<this->GetAnho()<<
            setw(15)<<"Vigencia: "<<this->IsVigente()<<endl;
}

void Revista::actualiza(int aa){
    if(anho<aa) vigente=false;
}