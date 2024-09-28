/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Pedido.h
 * Author: Lucas
 *
 * Created on 7 de julio de 2024, 01:50 PM
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
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Pedido();
    Pedido(const class Pedido &orig);
    virtual ~Pedido();
    //GETTERS Y SETTERS
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;
    //METODOS
    void operator =(const class Pedido &orig);
    bool operator <(const class Pedido &dato);
    void leerDatos(ifstream &arch);
    void mostrar(ofstream &arch);
};

//FUNCIONES

#endif /* PEDIDO_H */

