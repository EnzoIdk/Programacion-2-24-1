/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programacion.h
 * Author: margo
 *
 * Created on 7 de julio de 2024, 13:22
 */

#ifndef PROGRAMACION_H
#define PROGRAMACION_H
#include "Arbol.h"
#include "Flota.h"
class Programacion {
private:
    Arbol ADespachos;
    Flota fVehiculos;

public:
    Programacion();
    Programacion(const Programacion& orig);
    virtual ~Programacion();
    void  cargavehiculos();
    void  cargaprogramacion();
    void  reducevehiculos(int cant);
    void muestraprogramacion();
  //  friend class Flota;
};
#endif /* PROGRAMACION_H */

