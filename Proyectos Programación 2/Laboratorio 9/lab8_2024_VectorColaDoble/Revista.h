/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Revista.h
 * Author: margo
 *
 * Created on 20 de junio de 2024, 7:46
 */

#ifndef REVISTA_H
#define REVISTA_H

#include "Libro.h"
#include <fstream>
using namespace std;
class Revista : public Libro {
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
    void lee(ifstream&);
    void imprime(ofstream&);
    void actualiza();
};
#endif /* REVISTA_H */

