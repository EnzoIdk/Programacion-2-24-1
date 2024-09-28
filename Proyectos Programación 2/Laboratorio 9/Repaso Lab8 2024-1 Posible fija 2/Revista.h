/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Revista.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 21:14
 */

#ifndef REVISTA_H
#define REVISTA_H

#include "Libro.h"

class Revista:public Libro {
private:
    int ISSN;
    int anho;
    int numero;
    int vigencia;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Revista();
    Revista(const class Revista &orig);
    virtual ~Revista();
    //GETTERS Y SETTERS
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;
    //METODOS
    void lee(ifstream &arch);
    void actualiza();
    void imprime(ofstream &arch);
};

//FUNCIONES

#endif /* REVISTA_H */

