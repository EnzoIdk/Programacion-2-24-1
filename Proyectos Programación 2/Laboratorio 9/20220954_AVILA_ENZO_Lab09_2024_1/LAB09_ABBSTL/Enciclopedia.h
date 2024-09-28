/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Enciclopedia.h
 * Author: aml
 *
 * Created on 24 de junio de 2024, 09:47 AM
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include <fstream>
using namespace std;
#include "Libro.h"
class Enciclopedia:public Libro{
private:
    int sku;
    int anho;
public:
    Enciclopedia();
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* ENCICLOPEDIA_H */

