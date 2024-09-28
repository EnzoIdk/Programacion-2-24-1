/* 
 * Archivo:   Urgencia.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 11 de diciembre de 2020, 08:14 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Urgencia.h"

Urgencia::Urgencia() {

}

Urgencia::Urgencia(const Urgencia& orig) {
    *this = orig;
}

Urgencia::~Urgencia() {
    
}

void Urgencia::SetPorcUrgencia(double porcUrgencia) {
    this->porcUrgencia = porcUrgencia;
}

double Urgencia::GetPorcUrgencia() const {
    return porcUrgencia;
}

void Urgencia::SetPorcSeguro(double porcSeguro) {
    this->porcSeguro = porcSeguro;
}

double Urgencia::GetPorcSeguro() const {
    return porcSeguro;
}

void Urgencia::operator=(const Urgencia& urg) {
    char nomb[60], codM[10];
    this->SetDni(urg.GetDni());
    this->SetPorcSeguro(urg.GetPorcSeguro());
    this->SetPorcUrgencia(urg.GetPorcUrgencia());
    urg.GetNombre(nomb);
    urg.GetCodMed(codM);
    this->SetNombre(nomb);
    this->SetCodMed(codM);
}

int Urgencia::getPrioridad() {
    return 2;
}

void Urgencia::imprime(ofstream& arch) {
    char nomb[60], codM[10];
    this->GetNombre(nomb);
    this->GetCodMed(codM);
    arch << setw(10) << this->GetDni()
            << setw(5) << " "
            << left << setw(45) << nomb
            << right << setw(10) << codM
            << setw(15) << porcSeguro
            << setw(15) << porcUrgencia << endl;
}

void Urgencia::lee(ifstream& arch) {
    char codM[10], nomb[60];
    double porcSeg, porcTipo;
    int dni;
    arch >> dni; arch.get();
    arch.getline(nomb,60,',');
    arch.getline(codM,10,',');
    arch >> porcSeg; arch.get();
    arch >> porcTipo; arch.get();
    this->SetDni(dni);
    this->SetNombre(nomb);
    this->SetCodMed(codM);
    this->SetPorcSeguro(porcSeg);
    this->SetPorcUrgencia(porcTipo);
}

int Urgencia::seguro() {
    return porcSeguro > 0;
}
