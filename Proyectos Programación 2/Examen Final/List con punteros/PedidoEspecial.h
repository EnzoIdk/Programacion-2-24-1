/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoEspecial.h
 * Author: Enzo
 *
 * Created on 7 de julio de 2024, 11:21 PM
 */

#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H
#include <fstream>
using namespace std;
#include "Pedido.h"

class PedidoEspecial:public Pedido{
private:
    double descuento;
public:
    PedidoEspecial();
    PedidoEspecial(const PedidoEspecial& orig);
    virtual ~PedidoEspecial();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(int cod,ifstream &arch);
    void actualiza();
    void imprime(ofstream &arch,double,double);
};

#endif /* PEDIDOESPECIAL_H */

