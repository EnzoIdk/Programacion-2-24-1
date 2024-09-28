/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 03:06 PM
 */

#ifndef NODO_H
#define NODO_H
#include <fstream>
using namespace std;
#include "Pila.h"
#include "Vehiculo.h"
class Nodo {
private:
    class Vehiculo *unidad;
    class Nodo *sig;
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Pila;
};

#endif /* NODO_H */

