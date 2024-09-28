/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flota.h
 * Author: margo
 *
 * Created on 6 de julio de 2024, 19:32
 */

#ifndef FLOTA_H
#define FLOTA_H
#include <map>
#include <vector>
using namespace std;

#include "Vehiculo.h"

class Flota{
private:
    map <string,Vehiculo*> vehiculos;

public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    void cargar_vehiculos();
    void mostrar_vehiculos();
    void cargar_pedidos();
    void mostrarReporte(ofstream&arch,vector<string>&placas, int n);
    friend class Programacion;
};
#endif /* FLOTA_H */

