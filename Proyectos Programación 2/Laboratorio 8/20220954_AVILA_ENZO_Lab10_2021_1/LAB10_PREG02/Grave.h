/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Grave.h
 * Author: aml
 *
 * Created on 12 de junio de 2024, 03:17 PM
 */

#ifndef GRAVE_H
#define GRAVE_H
#include <fstream>
using namespace std;
#include "Infraccion.h"
class Grave:public Infraccion{
private:
    double descuento;
    int puntos;
public:
    Grave();
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &,int);
    void imprime(ofstream &);
};

#endif /* GRAVE_H */

