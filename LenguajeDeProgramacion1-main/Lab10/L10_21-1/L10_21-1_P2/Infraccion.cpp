/* 
 * File:   Infraccion.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de noviembre de 2022, 06:31 PM
 */

#include <cstring>

#include "Infraccion.h"

Infraccion::Infraccion() {
    codigo=0;
    gravedad=nullptr;
}



Infraccion::~Infraccion() {
    if(gravedad)delete gravedad;
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::SetGravedad(char* cad) {
    if(gravedad)delete gravedad;
    gravedad = new char [strlen(cad)+1];
    strcpy(gravedad,cad);
    
}

void Infraccion::GetGravedad(char* cad) const {
    if(gravedad)strcpy(cad,gravedad);
    else cad[0]=0;
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}

