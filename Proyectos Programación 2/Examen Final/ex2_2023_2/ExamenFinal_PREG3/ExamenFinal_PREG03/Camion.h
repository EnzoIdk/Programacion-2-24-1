/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camion.h
 * Author: margo
 *
 * Created on 6 de julio de 2024, 20:28
 */

#ifndef CAMION_H
#define CAMION_H
#include <vector>
#include <fstream>

#include "Vehiculo.h"
#include "Pedido.h"

class Camion : public Vehiculo {
private:
    int ejes;
    int llantas;
    vector<Pedido>depositos;
    double carga_actual;
    
public:
    Camion();
    Camion(const Camion& orig);
    virtual ~Camion();
    void SetCarga_actual(double carga_actual);
    double GetCarga_actual() const;
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    virtual void lee(ifstream &);
    virtual void imprimir(ofstream &);
    virtual void insertar(Pedido&);
};
#endif /* CAMION_H */

