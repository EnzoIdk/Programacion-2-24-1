/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Arbol.h
 * Author: Lucas
 *
 * Created on 7 de julio de 2024, 07:19 PM
 */

#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"
#include "Vehiculo.h"

class Arbol {
private:
    class Nodo * raiz;
    //
    void insertarRec(class Nodo * &parbol, class Vehiculo * vehiculo);
    void recorrerEnOrdenRec(class Nodo * parbol, ofstream &arch);
    void eliminarNodoRec(class Nodo * &parbol, int &cantidad);
    void eliminarRec(class Nodo * parbol);
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Arbol();
    Arbol(const class Arbol &orig);
    virtual ~Arbol();
    //GETTERS Y SETTERS
    //METODOS
    void insertar(class Vehiculo * vehiculo);
    void recorrerEnOrden(ofstream &arch);
    void eliminarNodo(int cantidad);
    void eliminar();
};

//FUNCIONES

#endif /* ARBOL_H */

