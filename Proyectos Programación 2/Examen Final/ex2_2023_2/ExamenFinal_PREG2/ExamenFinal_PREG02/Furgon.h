/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Furgon.h
 * Author: margo
 *
 * Created on 6 de julio de 2024, 17:43
 */

#ifndef FURGON_H
#define FURGON_H
#include <list>
#include <fstream>
#include "Vehiculo.h"
#include "Pedido.h"

using namespace std;
class Furgon : public Vehiculo{
private:
    int filas;
    int puertas;
    list<Pedido>depositos;
    
public:
    Furgon();
    Furgon(const Furgon& orig);
    virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    virtual void lee(ifstream &arch);
    virtual void imprimir(ofstream&);
    virtual void insertar(Pedido &ped);
};
#endif /* FURGON_H */

