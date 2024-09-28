/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enciclopedia.h
 * Author: alulab14
 *
 * Created on 14 de junio de 2024, 08:05 AM
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
    void lee(ifstream &);
    void actualiza();
    void imprime(ofstream &);
};

#endif /* ENCICLOPEDIA_H */

