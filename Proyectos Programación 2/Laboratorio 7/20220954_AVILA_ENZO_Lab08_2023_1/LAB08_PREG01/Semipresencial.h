/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Semipresencial.h
 * Author: Enzo
 *
 * Created on 28 de mayo de 2024, 04:50 PM
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include <fstream>
using namespace std;
#include "Alumno.h"
class Semipresencial:public Alumno{
private:
    double descuento;
    double total;
public:
    Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leerDatos(ifstream &);
    void actualiza(double);
    void imprime(ofstream &);
};

#endif /* SEMIPRESENCIAL_H */

