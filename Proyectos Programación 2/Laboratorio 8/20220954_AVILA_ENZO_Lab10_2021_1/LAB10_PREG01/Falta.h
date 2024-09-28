/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Falta.h
 * Author: aml
 *
 * Created on 12 de junio de 2024, 03:08 PM
 */

#ifndef FALTA_H
#define FALTA_H
#include <fstream>
using namespace std;

class Falta {
private:
    int licencia;
    int fecha;
    char *placa;
public:
    Falta();
    virtual ~Falta();
    void SetPlaca(const char*);
    void GetPlaca(char *) const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
    void leerDatos(ifstream &arch,int &);
    void operator =(const class Falta &orig);
    void imprimeF(ofstream &);
    void imprimeFecha(ofstream &);
};

#endif /* FALTA_H */

