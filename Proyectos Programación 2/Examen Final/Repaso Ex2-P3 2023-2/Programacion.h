/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Programacion.h
 * Author: Lucas
 *
 * Created on 7 de julio de 2024, 07:22 PM
 */

#ifndef PROGRAMACION_H
#define PROGRAMACION_H

#include "Arbol.h"
#include "Flota.h"

class Programacion {
private:
    class Arbol ADespachos;
    class Flota fvehiculos;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Programacion();
    Programacion(const class Programacion &orig);
    virtual ~Programacion();
    //GETTERS Y SETTERS
    //METODOS
    void cargavehiculos();
    void cargaprogramacion();
    void reducevehiculos(int cantidad);
    void muestraprogramacion();
};

//FUNCIONES

#endif /* PROGRAMACION_H */

