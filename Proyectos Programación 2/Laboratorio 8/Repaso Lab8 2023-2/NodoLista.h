/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NodoLista.h
 * Author: aml
 *
 * Created on 12 de junio de 2024, 12:45 PM
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "LVehiculos.h"

class NodoLista {
public:
    NodoLista();
    virtual ~NodoLista();
    
    friend class LVehiculos;
private:
    class Vehiculo * unidad;
    class NodoLista * sig;
};

#endif /* NODOLISTA_H */

