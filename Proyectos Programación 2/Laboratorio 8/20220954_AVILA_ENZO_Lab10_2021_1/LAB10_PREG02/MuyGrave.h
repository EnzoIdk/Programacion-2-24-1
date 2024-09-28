/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   MuyGrave.h
 * Author: aml
 *
 * Created on 12 de junio de 2024, 03:19 PM
 */

#ifndef MUYGRAVE_H
#define MUYGRAVE_H
#include <fstream>
using namespace std;
#include "Infraccion.h"
class MuyGrave:public Infraccion{
private:
    int puntos;
    int meses;
public:
    MuyGrave();
    void SetMeses(int meses);
    int GetMeses() const;
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void lee(ifstream &,int);
    void imprime(ofstream &);
};

#endif /* MUYGRAVE_H */

