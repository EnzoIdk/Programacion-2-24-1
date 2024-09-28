/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Enzo
 *
 * Created on 9 de junio de 2024, 09:31 AM
 */

#ifndef NODO_H
#define NODO_H
#include "Lista.h"
#include "Persona.h"
class Nodo {
public:
    Nodo();
    friend class Lista;
private:
    class Persona dato;
    class Nodo *siguiente;
};

#endif /* NODO_H */

