/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   paciente.h
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 07:35 AM
 */

#ifndef PACIENTE_H
#define PACIENTE_H

#include "cita.h"

class paciente {
private:
    int dni;
    char *nombre;
    cita lcitas[100];
    int telefono;
    double totalgastado;
public:
    paciente();
    paciente(const paciente& orig);
    virtual ~paciente();
    void SetTotalgastado(double totalgastado);
    double GetTotalgastado() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(const char *);
    void GetNombre(char *) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator +=(const class cita &cit);
    void operator ++(int);
    void ImprimirCitas(ofstream &);
};

void operator >>(ifstream &,paciente &pac);
void operator <<(ofstream &,paciente &pac);
void imprimirFecha(ofstream &arch,int fecha);
void imprimirLinea(ofstream &arch,int longitud,char simb);

#endif /* PACIENTE_H */

