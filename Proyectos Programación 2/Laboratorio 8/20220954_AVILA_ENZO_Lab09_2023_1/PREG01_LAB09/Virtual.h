/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Virtual.h
 * Author: Enzo
 *
 * Created on 7 de junio de 2024, 04:37 PM
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
    void SetLicencia(const char *lic);
    void GetLicencia(char *lic) const;
    void lee(ifstream &);
    void imprime(ofstream &);
    void actualizatotal(double);
};

#endif /* VIRTUAL_H */

