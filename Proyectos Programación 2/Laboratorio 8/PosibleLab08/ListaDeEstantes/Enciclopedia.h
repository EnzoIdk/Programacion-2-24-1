/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Enciclopedia.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 08:23 AM
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H
#include <fstream>
using namespace std;
#include "Libro.h"
class Enciclopedia:public Libro{
private:
    int volumen;
    double peso;
public:
    Enciclopedia();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetVolumen(int volumen);
    int GetVolumen() const;
    void leerLib(ifstream &);
    void imprimirLib(ofstream &);
};

#endif /* ENCICLOPEDIA_H */

