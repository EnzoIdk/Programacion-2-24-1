/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: alulab14
 *
 * Created on 22 de mayo de 2024, 11:16 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <fstream>
#include "ProductoEntregado.h"
#include "Pedido.h"

class Cliente {

public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(const char*);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator +=(const class Pedido &ped);
    void imprimirPedidos(ofstream &arch);
private:
    int dni;
    char *nombre;
    int telefono;
    ProductoEntregado productos_entregados[10];
    int cantidad_productos_entregados;
    double monto_total;
};

bool operator >> (ifstream &arch,class Cliente &cliente);
void operator << (ofstream &arch,class Cliente &cliente);
#endif /* CLIENTE_H */

