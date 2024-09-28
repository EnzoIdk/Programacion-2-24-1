/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Camion.h
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 10:31 AM
 */

#ifndef CAMION_H
#define CAMION_H
#include <fstream>
#include <vector>
using namespace std;
#include "Pedido.h"
#include "Vehiculo.h"
class Camion:public Vehiculo{
private:
    int ejes;
    int llantas;
    vector<class Pedido> depositos;
public:
    Camion();
    Camion(const Camion& orig);
    virtual ~Camion();
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    void leer(ifstream &arch);
    void mostrar(ofstream &arch);
    void insertar(const class Pedido &ped,double);
    double obtenerCargaActual();
    char getTipo() const;
};

#endif /* CAMION_H */

