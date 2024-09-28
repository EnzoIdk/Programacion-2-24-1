/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Novela.h
 * Author: alulab14
 *
 * Created on 14 de junio de 2024, 08:06 AM
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
    void lee(ifstream &);
    void actualiza();
    void imprime(ofstream &);
};

#endif /* NOVELA_H */

