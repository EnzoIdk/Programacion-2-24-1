/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 21:10
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>

#include "Enciclopedia.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

Enciclopedia::Enciclopedia() {
    vigencia=1;
}

Enciclopedia::Enciclopedia(const class Enciclopedia &orig) {

}

Enciclopedia::~Enciclopedia() {

}

//GETTERS Y SETTERS
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

//METODOS
void Enciclopedia::lee(ifstream& arch){
    int skuTemp, aaTemp;
    //
    this->Libro::lee(arch);
    arch>>skuTemp;
    arch.get();
    arch>>aaTemp;
    arch.get();
    //
    this->SetSku(skuTemp);
    this->SetAnho(aaTemp);
}

void Enciclopedia::actualiza(){
    if(anho<=2020) vigencia=0;
}

void Enciclopedia::imprime(ofstream& arch){
    this->Libro::imprime(arch);
    arch<<"SKU: "<<this->GetSku()<<setw(10)<<"Año: "<<this->GetAnho()<<setw(15)
            <<"Vigencia: "<<this->GetVigencia()<<endl;
}

//FUNCIONES
