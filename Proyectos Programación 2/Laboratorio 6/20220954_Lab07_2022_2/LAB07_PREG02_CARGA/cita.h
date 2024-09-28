/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   cita.h
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 07:36 AM
 */

#ifndef CITA_H
#define CITA_H

using namespace std;
#include "medico.h"

class cita {
private:
    int dni;
    int codigo;
    int fecha;
    double tarifa;
public:
    cita();
    cita(const cita& orig);
    virtual ~cita();
    void SetTarifa(double tarifa);
    double GetTarifa() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetDni(int dni);
    int GetDni() const;
    void operator <=(const class medico *arr);
};

void operator >>(ifstream &arch,cita &cit);

#endif /* CITA_H */

