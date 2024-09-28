/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Revista.h
 * Author: alulab14
 *
 * Created on 14 de junio de 2024, 08:06 AM
 */

#ifndef REVISTA_H
#define REVISTA_H
#include <fstream>
using namespace std;
#include "Libro.h"
class Revista:public Libro{
private:
    int ISSN;
    int anho;
    int numero;
    int vigencia;
public:
    Revista();
    Revista(const Revista& orig);
    virtual ~Revista();
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;
    void lee(ifstream &);
    void actualiza();
    void imprime(ofstream &);
};

#endif /* REVISTA_H */

