/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Flota.h
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 10:32 AM
 */

#ifndef FLOTA_H
#define FLOTA_H
#include <fstream>
#include <string>
#include <map>
#include <iterator>
using namespace std;
#include "Vehiculo.h"
#include "Programacion.h"

class Flota {
private:
    map<string,class Vehiculo *> vehiculos;
    void asignarMemoria(class Vehiculo *&aux,char tipo);
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    void cargar_vehiculos();
    void mostrar_vehiculos();
    void cargar_pedidos();
    friend class Programacion;
};

#endif /* FLOTA_H */

