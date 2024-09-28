/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NPedido.h
 * Author: aml
 *
 * Created on 12 de junio de 2024, 12:19 PM
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

#include "Vehiculo.h"

class NPedido {
public:
    NPedido();
    virtual ~NPedido();
    
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(char * cad);
    void GetCodigo(char * cad) const;
    //LA "PILA"
    friend class Vehiculo;
    //METODOS
    void setDatos(char * cod, int cant, double peso);
    void imprime(ofstream &arch);
private:
    char * codigo;
    int cantidad;
    double peso;
    class NPedido * sig;
};

#endif /* NPEDIDO_H */

