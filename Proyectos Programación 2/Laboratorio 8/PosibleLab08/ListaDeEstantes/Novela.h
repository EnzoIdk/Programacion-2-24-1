/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Novela.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 08:23 AM
 */

#ifndef NOVELA_H
#define NOVELA_H
#include <fstream>
using namespace std;
#include "Libro.h"
class Novela:public Libro{
private:
    char *tipo;
    double peso;
public:
    Novela();
    virtual ~Novela();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetTipo(const char*);
    void GetTipo(char*) const;
    void leerLib(ifstream &);
    void imprimirLib(ofstream &);
};

#endif /* NOVELA_H */

