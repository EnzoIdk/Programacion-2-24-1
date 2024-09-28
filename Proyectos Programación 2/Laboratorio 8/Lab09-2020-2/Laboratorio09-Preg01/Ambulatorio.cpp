/* 
 * Archivo:   Ambulatorio.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 11 de diciembre de 2020, 08:08 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Ambulatorio.h"

Ambulatorio::Ambulatorio() {

}

Ambulatorio::Ambulatorio(const Ambulatorio& orig) {
    *this = orig;
}

Ambulatorio::~Ambulatorio() {

}

void Ambulatorio::SetPorcSeguro(double PorcSeguro) {
    this->PorcSeguro = PorcSeguro;
}

double Ambulatorio::GetPorcSeguro() const {
    return PorcSeguro;
}

void Ambulatorio::operator=(const Ambulatorio& amb) {
    char nomb[60], codM[10];
    this->SetDni(amb.GetDni());
    this->SetPorcSeguro(amb.GetPorcSeguro());
    amb.GetNombre(nomb);
    amb.GetCodMed(codM);
    this->SetNombre(nomb);
    this->SetCodMed(codM);
}

int Ambulatorio::getPrioridad() {
    return 1;
}

void Ambulatorio::imprime(ofstream& arch) {
    char nomb[60], codM[10];
    this->GetNombre(nomb);
    this->GetCodMed(codM);
    arch << setw(10) << this->GetDni()
            << setw(5) << " "
            << left << setw(45) << nomb
            << right << setw(10) << codM
            << setw(15) << PorcSeguro << endl;
}

void Ambulatorio::lee(ifstream& arch) {
    double porcSeg;
    int dni;
    char codM[10], nomb[60];
    arch >> dni; arch.get();
    arch.getline(nomb,60,',');
    arch.getline(codM,10,',');
    arch >> porcSeg; arch.get(); 
    this->SetDni(dni);
    this->SetNombre(nomb);
    this->SetCodMed(codM);
    this->SetPorcSeguro(porcSeg);
}

int Ambulatorio::seguro() {
    return PorcSeguro > 0;
}