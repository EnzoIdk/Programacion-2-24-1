/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoEventual.h
 * Author: Enzo
 *
 * Created on 7 de julio de 2024, 11:20 PM
 */

#ifndef PEDIDOEVENTUAL_H
#define PEDIDOEVENTUAL_H
#include <fstream>
using namespace std;
#include "Pedido.h"
class PedidoEventual:public Pedido{
private:
    double flete;
public:
    PedidoEventual();
    PedidoEventual(const PedidoEventual& orig);
    virtual ~PedidoEventual();
    void SetFlete(double flete);
    double GetFlete() const;
    void lee(int cod,ifstream &arch);
    void actualiza();
    void imprime(ofstream &arch,double,double);
};

#endif /* PEDIDOEVENTUAL_H */

