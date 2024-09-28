/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Virtual.h
 * Author: Enzo
 *
 * Created on 28 de mayo de 2024, 09:54 PM
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include <fstream>
using namespace std;
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
    void leerDatos(ifstream &);
    void actualiza(double);
    void imprime(ofstream &);
};

#endif /* VIRTUAL_H */

