/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Novela.h
 * Author: aml
 *
 * Created on 24 de junio de 2024, 09:48 AM
 */

#ifndef NOVELA_H
#define NOVELA_H

#include <fstream>
using namespace std;
#include "Libro.h"
class Novela:public Libro{
private:
    char *autor;
public:
    Novela();
    virtual ~Novela();
    void SetAutor(const char *cad);
    void GetAutor(char *cad) const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* NOVELA_H */

