/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Leve.h
 * Author: aml
 *
 * Created on 12 de junio de 2024, 03:16 PM
 */

#ifndef LEVE_H
#define LEVE_H
#include <fstream>
using namespace std;
#include "Infraccion.h"
class Leve:public Infraccion{
private:
    double descuento;
public:
    Leve();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &,int);
    void imprime(ofstream &);
};

#endif /* LEVE_H */

