/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grave.h
 * Author: ISA
 *
 * Created on 6 de junio de 2024, 03:57 PM
 */

#ifndef GRAVE_H
#define GRAVE_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Infraccion.h"

class Grave: public Infraccion{
private:
    double descuento;
    int puntos;
public:
    Grave();
    Grave(const Grave& orig);
    virtual ~Grave();
    void operator = (const Grave& orig);
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    bool lee(ifstream &arch, int cod);
    void imprime(ofstream &arch);
};

#endif /* GRAVE_H */

