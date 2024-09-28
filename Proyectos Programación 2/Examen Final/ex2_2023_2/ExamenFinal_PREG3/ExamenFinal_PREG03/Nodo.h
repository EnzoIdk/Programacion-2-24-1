/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: margo
 *
 * Created on 7 de julio de 2024, 13:21
 */

#ifndef NODO_H
#define NODO_H

#include "Vehiculo.h"
#include "Arbol.h"


class Nodo {
private:
    Vehiculo *unidad;
    Nodo *izq;
    Nodo *der;

public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Arbol;
};
#endif /* NODO_H */

