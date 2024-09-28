/* 
 * Archivo:   Emergencia.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 11 de diciembre de 2020, 08:17 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Emergencia.h"

Emergencia::Emergencia() {
    nombreRef = nullptr;
}

Emergencia::Emergencia(const Emergencia& orig) {
    nombreRef = nullptr;
    *this = orig;
}

Emergencia::~Emergencia() {
    if (nombreRef != nullptr) delete []nombreRef;
}

void Emergencia::SetNombreRef(const char* nombR) {
    if (nombreRef) delete []nombreRef;
    nombreRef = new char [strlen(nombR)+1];
    strcpy(nombreRef,nombR);
}

void Emergencia::GetNombreRef(char* nombR) const {
    if (!nombreRef) nombreRef[0] = '\0';
    strcpy(nombR,nombreRef);
}

void Emergencia::SetTelefonoRef(int telefonoRef) {
    this->telefonoRef = telefonoRef;
}

int Emergencia::GetTelefonoRef() const {
    return telefonoRef;
}

void Emergencia::operator=(const Emergencia& emer) {
    char nomb[60], codM[10], nombR[60];
    this->SetDni(emer.GetDni()); 
    this->SetTelefonoRef(emer.GetTelefonoRef());
    emer.GetNombre(nomb);
    emer.GetCodMed(codM);
    emer.GetNombreRef(nombR);
    this->SetNombre(nomb);
    this->SetCodMed(codM);
    this->SetNombreRef(nombR);
}

int Emergencia::getPrioridad() {
    return 3;
}

void Emergencia::imprime(ofstream& arch) {
    char nomb[60], codM[10], nombR[60];
    this->GetNombre(nomb);
    this->GetCodMed(codM);
    this->GetNombreRef(nombR);
    arch << setw(10) << this->GetDni()
            << setw(5) << " "
            << left << setw(45) << nomb
            << right << setw(10) << codM
            << setw(5) << " "
            << left << setw(30) << nombR           
            << right << setw(10) << telefonoRef << endl;  
}

void Emergencia::lee(ifstream& arch) {
    char nombR[60], codM[10], nomb[60];
    int telef, dni;
    arch >> dni; arch.get();
    arch.getline(nomb,60,',');
    arch.getline(codM,10,',');
    arch.getline(nombR,60,',');   
    arch >> telef; arch.get();
    this->SetDni(dni);
    this->SetNombre(nomb);
    this->SetCodMed(codM);
    this->SetNombreRef(nombR);
    this->SetTelefonoRef(telef);
}

int Emergencia::seguro() {
    return 0;
}
