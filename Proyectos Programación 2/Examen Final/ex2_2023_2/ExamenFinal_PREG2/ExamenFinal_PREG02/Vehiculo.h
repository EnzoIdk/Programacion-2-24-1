/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.h
 * Author: margo
 *
 * Created on 6 de julio de 2024, 17:42
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
#include <fstream>
#include "Pedido.h"
using namespace std;
class Vehiculo {
private:
    int dni;
    string placa;
    double carga_maxima;
    double carga_actual;

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
    virtual void lee(ifstream &arch);
    virtual void imprimir(ofstream&);
    virtual void insertar(Pedido &)=0;//método abstracto
};
#endif /* VEHICULO_H */

