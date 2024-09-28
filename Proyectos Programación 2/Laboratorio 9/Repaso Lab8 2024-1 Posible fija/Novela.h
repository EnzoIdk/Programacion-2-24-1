/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Novela.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 18:51
 */

#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"

class Novela:public Libro {
private:
    char * autor;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Novela();
    Novela(const class Novela &orig);
    virtual ~Novela();
    //GETTERS Y SETTERS
    void SetAutor(char * cad);
    void GetAutor(char * cad) const;
    //METODOS
    void lee(ifstream &arch);
    void actualiza(int aa);
    void imprime(ofstream &arch);
};

//FUNCIONES

#endif /* NOVELA_H */

