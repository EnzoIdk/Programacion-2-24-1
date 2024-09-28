/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Novela.h
 * Author: margo
 *
 * Created on 20 de junio de 2024, 7:42
 */

#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"

#include <fstream>
using namespace std;
class Novela : public Libro {
private:
    char *autor;

public:
    Novela();
    Novela(const Novela& orig);
    virtual ~Novela();
    void SetAutor(const char* autor);
    void GetAutor(char*) const;
    void lee(ifstream&);
    void imprime(ofstream&);
    void actualiza();
};
#endif /* NOVELA_H */

