/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Virtual.h
 * Author: Enzo
 *
 * Created on 11 de junio de 2024, 08:35 PM
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include "Alumno.h"
class Virtual:public Alumno{
private:
    char *licencia;
    double total;
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char*);
    void GetLicencia(char *) const;
    void lee(ifstream &);
    void imprime(ofstream &);
    void actualizatotal(double);
};

#endif /* VIRTUAL_H */

