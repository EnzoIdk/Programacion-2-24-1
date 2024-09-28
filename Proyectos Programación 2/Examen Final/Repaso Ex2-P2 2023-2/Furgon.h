/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Furgon.h
 * Author: Lucas
 *
 * Created on 7 de julio de 2024, 02:25 PM
 */

#ifndef FURGON_H
#define FURGON_H

#include <fstream>
#include <list>
using namespace std;

#include "Vehiculo.h"
#include "Pedido.h"

class Furgon:public Vehiculo {
private:
    int filas;
    int puertas;
    list<class Pedido> depositos; //ORDENADOS POR PESO
    //
    void insertarEnOrden(const class Pedido &pedido);
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Furgon();
    Furgon(const class Furgon &orig);
    virtual ~Furgon();
    //GETTERS Y SETTERS
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    //METODOS
    void leer(ifstream &arch);
    void mostrar(ofstream &arch);
    void insertar(const class Pedido &pedido);
};

//FUNCIONES

#endif /* FURGON_H */

