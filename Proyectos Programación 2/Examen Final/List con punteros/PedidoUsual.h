/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoUsual.h
 * Author: Enzo
 *
 * Created on 7 de julio de 2024, 11:20 PM
 */

#ifndef PEDIDOUSUAL_H
#define PEDIDOUSUAL_H
#include <fstream>
using namespace std;
#include "Pedido.h"
class PedidoUsual:public Pedido{
private:
    double flete;
    double descuento;
public:
    PedidoUsual();
    PedidoUsual(const PedidoUsual& orig);
    virtual ~PedidoUsual();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetFlete(double flete);
    double GetFlete() const;
    void lee(int cod,ifstream &);
    void actualiza();
    void imprime(ofstream &,double,double);
};

#endif /* PEDIDOUSUAL_H */

