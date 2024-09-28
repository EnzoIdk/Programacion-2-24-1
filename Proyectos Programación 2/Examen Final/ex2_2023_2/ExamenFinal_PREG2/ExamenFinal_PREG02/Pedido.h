/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: margo
 *
 * Created on 7 de julio de 2024, 6:49
 */

#ifndef PEDIDO_H
#define PEDIDO_H

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
    void lee(ifstream&);
    void imprime(ofstream&);
};
#endif /* PEDIDO_H */

