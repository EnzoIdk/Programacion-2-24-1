/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Emergencia.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 10:44 PM
 */

#ifndef EMERGENCIA_H
#define EMERGENCIA_H
#include <fstream>
using namespace std;
#include "Paciente.h"
class Emergencia:public Paciente{
private:
    int telefonoRef;
    char *nombreRef;
public:
    Emergencia();
    virtual ~Emergencia();
    void SetNombreRef(const char*);
    void GetNombreRef(char *) const;
    void SetTelefonoRef(int telefonoRef);
    int GetTelefonoRef() const;
    void lee(ifstream &);
    int getPrioridad() const;
    void imprime(ofstream &);
    bool tieneSeguro() const;
};

#endif /* EMERGENCIA_H */

