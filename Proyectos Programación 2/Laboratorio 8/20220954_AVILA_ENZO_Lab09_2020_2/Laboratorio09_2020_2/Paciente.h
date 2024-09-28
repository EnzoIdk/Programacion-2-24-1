/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Paciente.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 10:44 PM
 */

#ifndef PACIENTE_H
#define PACIENTE_H
#include <fstream>
using namespace std;

class Paciente {
private:
    int dni;
    char *nombre;
    int codMed;
public:
    Paciente();
    virtual ~Paciente();
    void SetNombre(const char*);
    void GetNombre(char *) const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCodMed(int codMed);
    int GetCodMed() const;
    virtual void lee(ifstream &);
    virtual int getPrioridad() const =0;
    virtual void imprime(ofstream &);
    virtual bool tieneSeguro() const=0;
};

#endif /* PACIENTE_H */

