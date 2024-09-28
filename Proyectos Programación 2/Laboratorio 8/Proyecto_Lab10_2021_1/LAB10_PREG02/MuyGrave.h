/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MuyGrave.h
 * Author: ISA
 *
 * Created on 6 de junio de 2024, 04:00 PM
 */

#ifndef MUYGRAVE_H
#define MUYGRAVE_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Infraccion.h"

class MuyGrave: public Infraccion{
private:
    int puntos;
    int meses;
public:
    MuyGrave();
    MuyGrave(const MuyGrave& orig);
    virtual ~MuyGrave();
    void operator = (const MuyGrave& orig);
    void SetMeses(int meses);
    int GetMeses() const;
    void SetPuntos(int puntos);
    int GetPuntos() const;
    bool lee(ifstream &arch, int cod);
    void imprime(ofstream &arch);
};

#endif /* MUYGRAVE_H */

