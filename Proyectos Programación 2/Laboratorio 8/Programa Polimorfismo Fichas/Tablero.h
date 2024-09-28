/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tablero.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2024, 11:58 AM
 */

#ifndef TABLERO_H
#define TABLERO_H
#include <fstream>
using namespace std;
#include "Ficha.h"
class Tablero {
public:
    Tablero();
    virtual ~Tablero();
    void leerFichas(ifstream &);
    void colocarFicha(char*,char,int,int);
    void leerMovimientos(ifstream &);
    void moverFicha(char*,char,int);
    void imprimeDatos(ofstream &);
private:
    class Ficha *ficha[100];
    int numFichas;  
};

#endif /* TABLERO_H */

