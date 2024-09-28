/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Enciclopedia.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 09:01 PM
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
    int vigencia;
public:
    Enciclopedia();
    Enciclopedia(const Enciclopedia& orig);
    virtual ~Enciclopedia();
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza();
};

#endif /* ENCICLOPEDIA_H */

