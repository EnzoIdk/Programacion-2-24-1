/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Presencial.h
 * Author: Enzo
 *
 * Created on 7 de junio de 2024, 04:32 PM
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
    void lee(ifstream &);
    void imprime(ofstream &);
    void actualizatotal(double);
};

#endif /* PRESENCIAL_H */

