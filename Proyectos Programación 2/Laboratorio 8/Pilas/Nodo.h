/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Usuario
 *
 * Created on 5 de junio de 2024, 01:21 PM
 */

#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

class Nodo {
public:
    Nodo();
    Nodo(void *&dato);
    ~Nodo();
    
    friend class Pila;
private:
    void *dato;
    Nodo *siguiente;
};

#endif /* NODO_H */

