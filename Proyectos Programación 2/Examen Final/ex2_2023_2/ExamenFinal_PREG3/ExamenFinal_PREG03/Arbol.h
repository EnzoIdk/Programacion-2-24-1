/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: margo
 *
 * Created on 7 de julio de 2024, 13:22
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
class Arbol {
private:
    class Nodo* raiz;
    void insertarRec(Vehiculo*&, Nodo*&);
    void reduccionRec(int& cat, Nodo*&);
    void enOrdenRec(ofstream&, Nodo*&);
public:
    Arbol();
    Arbol(const Arbol& orig);
    virtual ~Arbol();
    void insertarNodo(Vehiculo *&);
    void reducirVehiculos(int cat);
    void muestraprogramacion(ofstream&);
};
#endif /* ARBOL_H */

