/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: aml
 *
 * Created on 22 de mayo de 2024, 12:55 PM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "Pedido.h"
using namespace std;
class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);
    int GetCantidad_clientes_no_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(const char *desc);
    void GetDescripcion(char *desc) const;
    void SetCodigo(const char *cod);
    void GetCodigo(char *cod) const;
    bool operator +=(const class Pedido &ped);
    void ImprimirClientes(ofstream &arch);
private:
    char *codigo;
    char *descripcion;
    double precio;
    int stock;
    int clientes_servidos[20];
    int clientes_no_servidos[20];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
};

bool operator >>(ifstream &arch,class Producto &prod);
void operator <<(ofstream &arch,class Producto &prod);

#endif /* PRODUCTO_H */

