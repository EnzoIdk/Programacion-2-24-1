/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 10:30 AM
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
#include <string>
using namespace std;

class Pedido {
private:
    string codigo;
    int cantidad;
    double peso;
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;
    void operator =(const class Pedido &orig);
    bool operator <(const class Pedido &orig);
    void leerDatos(ifstream &arch);
    void mostrar(ofstream &arch);
};

#endif /* PEDIDO_H */

