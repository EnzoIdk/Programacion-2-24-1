/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Camion.h
 * Author: Lucas
 *
 * Created on 7 de julio de 2024, 01:55 PM
 */

#ifndef CAMION_H
#define CAMION_H

#include <fstream>
#include <vector>
using namespace std;

#include "Vehiculo.h"
#include "Pedido.h"

class Camion:public Vehiculo {
private:
    int ejes;
    int llantas;
    vector<class Pedido> depositos; //5 COMO MAXIMO
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Camion();
    Camion(const class Camion &orig);
    virtual ~Camion();
    //GETTERS Y SETTERS
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    //METODOS
    void leer(ifstream &arch);
    void mostrar(ofstream &arch);
    void insertar(const class Pedido &pedido);
};

//FUNCIONES

#endif /* CAMION_H */

