/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Furgon.h
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 10:31 AM
 */

#ifndef FURGON_H
#define FURGON_H
#include <fstream>
#include <list>
#include <iterator>
using namespace std;
#include "Pedido.h"
#include "Vehiculo.h"
class Furgon:public Vehiculo{
private:
    int filas;
    int puertas;
    list<class Pedido> depositos;
public:
    Furgon();
    Furgon(const Furgon& orig);
    virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void leer(ifstream &arch);
    void mostrar(ofstream &arch);
    void insertar(const class Pedido &ped,double);
    double obtenerCargaActual();
    void insertarEnOrden(const class Pedido &ped);
};

#endif /* FURGON_H */

