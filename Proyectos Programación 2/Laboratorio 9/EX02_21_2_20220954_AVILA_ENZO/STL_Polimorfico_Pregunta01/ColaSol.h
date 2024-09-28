/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ColaSol.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 02:12 PM
 */

#ifndef COLASOL_H
#define COLASOL_H
#include <fstream>
#include "NodoCola.h"
using namespace std;

class ColaSol {
private:
    class NodoCola *inicola;
    class NodoCola *fincola;
    int n;
public:
    ColaSol();
    virtual ~ColaSol();
    void encolar(char *cad,int carne);
    void desencolar(char *cad,int &carne);
    void setN(int n);
    int getN() const;
};

#endif /* COLASOL_H */

