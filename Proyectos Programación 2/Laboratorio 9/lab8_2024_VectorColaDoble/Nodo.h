/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: margo
 *
 * Created on 20 de junio de 2024, 19:54
 */

#ifndef NODO_H
#define NODO_H

#include "Libro.h"


class Nodo {
private:
    Nodo* sig;
    Nodo * ant;
    Libro *ptr;
    
public:
    Nodo();
//    Nodo( Libro*&);
//    Nodo(const Nodo& orig);
//    virtual ~Nodo();
    friend class LLibros;
};
#endif /* NODO_H */

