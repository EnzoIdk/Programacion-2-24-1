/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Revista.h
 * Author: Lucas
 *
 * Created on 8 de julio de 2024, 07:48 PM
 */

#ifndef REVISTA_H
#define REVISTA_H

#include "Libro.h"

class Revista:public Libro {
private:
    int ISSN;
    int anho;
    int numero;
    bool vigente;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Revista();
    Revista(const class Revista &orig);
    virtual ~Revista();
    //GETTERS Y SETTERS
    void SetVigente(bool vigente);
    bool IsVigente() const;
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;
    //METODOS
    void leer(ifstream &arch);
    void actualiza(int aa);
    void imprimir(ofstream &arch);
};

//FUNCIONES

#endif /* REVISTA_H */

