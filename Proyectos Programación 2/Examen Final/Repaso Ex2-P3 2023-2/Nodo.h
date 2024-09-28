/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Nodo.h
 * Author: Lucas
 *
 * Created on 7 de julio de 2024, 07:10 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Arbol.h"

class Nodo {
private:
    class Vehiculo * unidad;
    class Nodo * izq;
    class Nodo * der;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Nodo();
    Nodo(const class Nodo &orig);
    virtual ~Nodo();
    //GETTERS Y SETTERS
    //METODOS
    friend class Arbol;
};

//FUNCIONES

#endif /* NODO_H */

