/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Paciente.h"

//Paciente::Paciente() {
//}
//
//Paciente::Paciente(const Paciente& orig) {
//    *this=orig;
//}

//void Paciente::operator=(const Paciente& orig) {
//    char nomb[60];
//    char cod[60];
//    dni = orig.dni;
//    orig.getNombre(nomb);
//    setNombre(nomb);
//    fechaUltimaConsulta = orig.fechaUltimaConsulta;
//    orig.getCodigoDelMedicoDeUltimaConsulta(codigoDelMedicoDeUltimaConsulta);
//    setCodigoDelMedicoDeUltimaConsulta(cod);
//}

void Paciente::leerPaciente(ifstream& arch) {
    int dd, mm, aa;
    char c, cad[60];
    arch >> dd;
    if (arch.eof()) return;
    arch >> c >> mm >> c >> aa >> c >> dni >> c;
    fechaUltimaConsulta = dd+mm*100+aa*10000;
    arch.getline(cad, 60, ',');
    setNombre(cad);
    arch.getline(cad, 60, ',');
    setCodigoDelMedicoDeUltimaConsulta(cad);
}

void Paciente::imprimirPaciente(ofstream& arch) {
    arch << left << setw(10) << dni << setw(50) << nombre << 
            fechaUltimaConsulta << setw(10)<<codigoDelMedicoDeUltimaConsulta<<right<<endl;
}

void Paciente::setCodigoDelMedicoDeUltimaConsulta(const char*cad) {
    if (codigoDelMedicoDeUltimaConsulta) delete codigoDelMedicoDeUltimaConsulta;
    codigoDelMedicoDeUltimaConsulta = new char[strlen(cad)+1];
    strcpy(codigoDelMedicoDeUltimaConsulta, cad);
}

void Paciente::getCodigoDelMedicoDeUltimaConsulta(char*cad) const {
    if (codigoDelMedicoDeUltimaConsulta) strcpy(cad, codigoDelMedicoDeUltimaConsulta);
    else cad[0] = 0;
}

void Paciente::setFechaUltimaConsulta(int fechaUltimaConsulta) {
    this->fechaUltimaConsulta = fechaUltimaConsulta;
}

int Paciente::getFechaUltimaConsulta() const {
    return fechaUltimaConsulta;
}

void Paciente::setNombre(const char* cad) {
    if (nombre) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Paciente::getNombre(char *cad) const {
    if (nombre) strcpy(cad, nombre);
    else cad[0] = 0;
}

void Paciente::setDni(int dni) {
    this->dni = dni;
}

int Paciente::getDni() const {
    return dni;
}
