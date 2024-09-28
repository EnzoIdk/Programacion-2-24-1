/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Flota.h
 * Author: Lucas
 *
 * Created on 7 de julio de 2024, 03:11 PM
 */

#ifndef FLOTA_H
#define FLOTA_H

#include <string>
#include <map>
using namespace std;

#include "Vehiculo.h"
#include "Programacion.h"

class Flota {
private:
    map<string, class Vehiculo *> vehiculos;
    //
    void asignarTipo(class Vehiculo * &temp, char tipo);
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Flota();
    Flota(const class Flota &orig);
    virtual ~Flota();
    //GETTERS Y SETTERS
    //METODOS
    void cargar_vehiculos(const char * nomb);
    void mostrar_vehiculos(const char * nomb);
    void cargar_pedidos(const char * nomb);
    friend class Programacion;
};

//FUNCIONES

#endif /* FLOTA_H */

