/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Biblioteca.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 21:24
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Lista.h"

class Biblioteca {
private:
    class Lista lestantes;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Biblioteca();
    Biblioteca(const class Biblioteca &orig);
    virtual ~Biblioteca();
    //GETTERS Y SETTERS
    //METODOS
    void carga(const char * nomb);
    void llena(const char * nomb);
    void baja();
    void muestra(const char * nomb);
};

//FUNCIONES

#endif /* BIBLIOTECA_H */

