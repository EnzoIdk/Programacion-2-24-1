/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Flota.h
 * Author: aml
 *
 * Created on 12 de junio de 2024, 12:52 PM
 */

#ifndef FLOTA_H
#define FLOTA_H

#include "LVehiculos.h"

class Flota {
public:
    Flota();
    virtual ~Flota();
    
    void cargaFlota(const char * nomb);
    void muestraCarga(const char * nomb);
    void cargaPedidos(const char * nomb);
private:
    class LVehiculos lista;
};

#endif /* FLOTA_H */

