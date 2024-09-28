/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   NVehiculo.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 12:25
 */

#ifndef NVEHICULO_H
#define NVEHICULO_H

#include <fstream>
using namespace std;

#include "Vehiculo.h"

class NVehiculo {
private:
    class Vehiculo * unidad;
    //
    void asignaVehiculo(char tipo);
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    NVehiculo();
    NVehiculo(const class NVehiculo &orig);
    virtual ~NVehiculo();
    //GETTERS Y SETTERS
    //METODOS
    void operator =(const class NVehiculo &orig);
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    bool operator <(const class NVehiculo &dato) const;
    void eliminar();
    bool compararCliente(int dni) const;
    void agregarPedido(ifstream &arch);
//    void SetNull();
};

//FUNCIONES

#endif /* NVEHICULO_H */

