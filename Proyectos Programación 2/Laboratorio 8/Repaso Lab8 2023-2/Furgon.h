/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Furgon.h
 * Author: aml
 *
 * Created on 12 de junio de 2024, 12:41 PM
 */

#ifndef FURGON_H
#define FURGON_H

#include "Vehiculo.h"

class Furgon:public Vehiculo {
public:
    Furgon();
    virtual ~Furgon();
    
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
private:
    int filas;
    int puertas;
};

#endif /* FURGON_H */

