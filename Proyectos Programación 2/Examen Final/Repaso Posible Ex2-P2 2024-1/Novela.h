/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Novela.h
 * Author: Lucas
 *
 * Created on 8 de julio de 2024, 07:47 PM
 */

#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"

class Novela:public Libro {
private:
    string autor;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Novela();
    Novela(const class Novela &orig);
    virtual ~Novela();
    //GETTERS Y SETTERS
    void SetAutor(string autor);
    string GetAutor() const;
    //METODOS
    void leer(ifstream &arch);
    void actualiza(int aa);
    void imprimir(ofstream &arch);
};

//FUNCIONES

#endif /* NOVELA_H */

