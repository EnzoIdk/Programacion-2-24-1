/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 18:48
 */

#include <iostream>
#include <iomanip>
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

void Enciclopedia::SetSku(int sky) {
    this->sku = sky;
}

int Enciclopedia::GetSku() const {
    return sku;
}

//METODOS
void Enciclopedia::lee(ifstream &arch){
    int skuTemp, aaTemp;
    this->Libro::lee(arch);
    //78323,2015
    arch>>skuTemp;
    arch.get();
    arch>>aaTemp;
    arch.get();
    //
    this->SetSku(skuTemp);
    this->SetAnho(aaTemp);
}

void Enciclopedia::actualiza(int aa){
    if(anho<=aa) vigencia=0;
}

void Enciclopedia::imprime(ofstream& arch){
    this->Libro::imprime(arch);
    arch<<"SKU: "<<this->GetSku()<<setw(10)<<"Año: "<<this->GetAnho()<<setw(15)
            <<"Vigencia: "<<this->GetVigencia()<<endl;
}

//FUNCIONES
