/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pila.h
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 03:28 PM
 */

#ifndef PILA_H
#define PILA_H
#include <fstream>
using namespace std;
#include "Nodo.h"
#include "Vehiculo.h"
class Pila {
private:
    class Nodo *pila;
    void eliminarPila();
public:
    Pila();
    Pila(const Pila& orig);
    virtual ~Pila();
    void apilar(class Vehiculo *vehiculo);
    void imprimir(ofstream &arch);
    void desapilar(string &);
    class Vehiculo * desapilar();
};

#endif /* PILA_H */

