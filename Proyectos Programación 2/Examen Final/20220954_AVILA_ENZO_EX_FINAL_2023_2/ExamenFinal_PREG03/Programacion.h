/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Programacion.h
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 03:28 PM
 */

#ifndef PROGRAMACION_H
#define PROGRAMACION_H
#include <fstream>
using namespace std;
#include "Pila.h"
#include "Flota.h"
class Programacion {
private:
    class Pila PDespachos;
    class Pila PAux;
    Flota fVehiculos;
public:
    Programacion();
    Programacion(const Programacion& orig);
    virtual ~Programacion();
    void cargavehiculos();
    void cargaprogramacion();
    void reducevehiculos(int cant);
    void muestraprogramacion();
};

#endif /* PROGRAMACION_H */

