/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: Lucas
 * 
 * Created on 8 de julio de 2024, 07:46 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Enciclopedia.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
Enciclopedia::Enciclopedia() {
    vigente=true;
}

Enciclopedia::Enciclopedia(const class Enciclopedia &orig) {

}

Enciclopedia::~Enciclopedia() {

}

//GETTERS Y SETTERS
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

void Enciclopedia::SetVigente(bool vigente) {
    this->vigente = vigente;
}

bool Enciclopedia::IsVigente() const {
    return vigente;
}

//METODOS
void Enciclopedia::leer(ifstream &arch){
    int skuTemp, aaTemp;
    //E,ENCICLOPEDIA SALVAT,2000,12,78323,2015
    this->Libro::leer(arch);
    //78323,2015
    arch>>skuTemp;
    arch.get(); //,
    arch>>aaTemp;
    arch.get(); //\n
    //GUARDAMOS
    this->SetAnho(aaTemp);
    this->SetSku(skuTemp);
}

void Enciclopedia::imprimir(ofstream &arch){
    this->Libro::imprimir(arch);
    arch<<"SKU: "<<this->GetSku()<<setw(10)<<"Año: "<<this->GetAnho()<<setw(15)
            <<"Vigencia: "<<this->IsVigente()<<endl;
}

void Enciclopedia::actualiza(int aa){
    if(anho<aa) vigente=false;
}

//FUNCIONES
