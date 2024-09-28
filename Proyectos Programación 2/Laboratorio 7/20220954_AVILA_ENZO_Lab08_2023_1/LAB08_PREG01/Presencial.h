/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Presencial.h
 * Author: Enzo
 *
 * Created on 28 de mayo de 2024, 04:29 PM
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include <fstream>
using namespace std;
#include "Alumno.h"
class Presencial:public Alumno{
private:
    double recargo;
    double total;
public:
    Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void leerDatos(ifstream &);
    void actualiza(double);
    void imprime(ofstream &);
};

#endif /* PRESENCIAL_H */

