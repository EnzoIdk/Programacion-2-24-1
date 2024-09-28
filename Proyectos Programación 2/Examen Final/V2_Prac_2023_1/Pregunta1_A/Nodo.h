/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 06:53 PM
 */

#ifndef NODO_H
#define NODO_H

#include "AlumnoNotas.h"


class Nodo {
public:
    Nodo();
//    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class ListaDoble;
private:
    AlumnoNotas dato;
    Nodo *siguiente;
    Nodo *anterior;
};

#endif /* NODO_H */

