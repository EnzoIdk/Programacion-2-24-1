/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Flota.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 12:27
 */

#ifndef FLOTA_H
#define FLOTA_H

#include <fstream>
#include <vector>
using namespace std;

#include "NVehiculo.h"

class Flota {
private:
    class vector<class NVehiculo> vflota;
    //
    void imprimirLinea(ofstream &arch, char car);
    int buscarCliente(int dni);
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Flota();
    Flota(const class Flota &orig);
    virtual ~Flota();
    //GETTERS Y SETTERS
    //METODOS
    void cargaFlota(const char * nomb);
    void muestraCarga(const char * nomb);
    void cargaPedidos(const char * nomb);
};

//FUNCIONES

#endif /* FLOTA_H */

