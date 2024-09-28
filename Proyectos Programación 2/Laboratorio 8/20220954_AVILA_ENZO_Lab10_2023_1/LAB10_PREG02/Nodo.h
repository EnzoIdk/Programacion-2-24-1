/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Enzo
 *
 * Created on 11 de junio de 2024, 09:43 PM
 */

#ifndef NODO_H
#define NODO_H
#include "Boleta.h"
#include "Arbol.h"
class Nodo {
private:
    class Boleta dboleta;
    class Nodo *izq;
    class Nodo *der;
public:
    Nodo();
    friend class Arbol;
};

#endif /* NODO_H */

