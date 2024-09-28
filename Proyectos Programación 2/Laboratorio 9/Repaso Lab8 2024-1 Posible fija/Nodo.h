/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Nodo.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 18:53
 */

#ifndef NODO_H
#define NODO_H

#include "Libro.h"
#include "Lista.h"

class Nodo {
private:
    class Libro * plibro;
    class Nodo * sig;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Nodo();
    Nodo(const class Nodo &orig);
    virtual ~Nodo();
    //GETTERS Y SETTERS
    //METODOS
    friend class Lista;
};

//FUNCIONES

#endif /* NODO_H */

