/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: margo
 *
 * Created on 11 de junio de 2024, 18:32
 */

#ifndef NODO_H
#define NODO_H

#include "FIchas.h"
#include "Nodo.h"


class Nodo {
private:
    class FIchas *ptr;
    class Nodo *siguiente;

public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    void asignaMemoria(char);
    void rellenaFicha(char*, char, int ,int);
    friend class Lista;
    Nodo operator = (Nodo *);
};

#endif /* NODO_H */

