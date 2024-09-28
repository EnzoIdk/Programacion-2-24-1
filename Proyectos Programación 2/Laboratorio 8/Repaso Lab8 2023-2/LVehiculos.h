/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   LVehiculos.h
 * Author: aml
 *
 * Created on 12 de junio de 2024, 12:48 PM
 */

#ifndef LVEHICULOS_H
#define LVEHICULOS_H

#include <fstream>
using namespace std;

#include "Vehiculo.h"

class LVehiculos {
public:
    LVehiculos();
    virtual ~LVehiculos();
    
    void crear(ifstream &arch);
    void insertar(class Vehiculo * vehiculo);
    void imprime(ofstream &arch);
    void actualizar(ifstream &arch);
private:
    class NodoLista * lini;
    class NodoLista * lfin;
    //METODOS
    void asignarMemoria(class Vehiculo * &vehiculo, char tipo);
    void crearPedido(int codTemp, char * idPed, int cantTemp, double pesoTemp);
};

#endif /* LVEHICULOS_H */

