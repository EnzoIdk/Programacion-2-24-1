/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Vehiculo.h
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 10:31 AM
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include <fstream>
#include <string>
using namespace std;
#include "Pedido.h"

class Vehiculo {
private:
    int dni;
    string placa;
    double carga_maxima;
    double carga_actual;
    void imprimirLinea(ofstream &arch,int tam,char car);
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void SetCarga_actual(double carga_actual);
    double GetCarga_actual() const;
    void SetCarga_maxima(double carga_maxima);
    double GetCarga_maxima() const;
    void SetPlaca(string placa);
    string GetPlaca() const;
    void SetDni(int dni);
    int GetDni() const;
    virtual void leer(ifstream &arch);
    virtual void mostrar(ofstream &arch);
    virtual void insertar(const class Pedido &ped,double totalActual)=0;
    bool hayEspacio(double peso,double cargaActual);
    virtual double obtenerCargaActual()=0;
    virtual char getTipo() const =0;
};

#endif /* VEHICULO_H */

