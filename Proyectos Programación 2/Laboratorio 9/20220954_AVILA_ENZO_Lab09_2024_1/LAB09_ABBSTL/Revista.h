/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Revista.h
 * Author: aml
 *
 * Created on 24 de junio de 2024, 09:48 AM
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
public:
    Revista();
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* REVISTA_H */

