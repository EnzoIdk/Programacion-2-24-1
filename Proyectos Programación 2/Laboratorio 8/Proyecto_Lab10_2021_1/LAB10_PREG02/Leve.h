/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Leve.h
 * Author: ISA
 *
 * Created on 6 de junio de 2024, 03:56 PM
 */

#ifndef LEVE_H
#define LEVE_H
#include <fstream>
using namespace std;
#include "Infraccion.h"

class Leve: public Infraccion{
private:
    double descuento;
public:
    Leve();
    Leve(const Leve& orig);
    virtual ~Leve();
    void operator = (const Leve& orig);
    void SetDescuento(double descuento);
    double GetDescuento() const;
    bool lee(ifstream &arch, int cod);
    void imprime(ofstream &arch);
};

#endif /* LEVE_H */

