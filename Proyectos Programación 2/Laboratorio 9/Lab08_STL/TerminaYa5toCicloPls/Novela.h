/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Novela.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 09:08 PM
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
    Novela(const Novela& orig);
    virtual ~Novela();
    void SetAutor(const char *cad);
    void GetAutor(char *cad) const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza();
};

#endif /* NOVELA_H */

