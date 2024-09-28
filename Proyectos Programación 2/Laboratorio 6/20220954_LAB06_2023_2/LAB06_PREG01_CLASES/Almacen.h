/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Almacen.h
 * Author: aml
 *
 * Created on 22 de mayo de 2024, 01:12 PM
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include "Cliente.h"
#include "Producto.h"
class Almacen {
public:
    Almacen();
    Almacen(const Almacen& orig);
    virtual ~Almacen();
    void SetCantidad_productos(int cantidad_productos);
    int GetCantidad_productos() const;
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
private:
    Cliente arreglo_clientes[200];
    int cantidad_clientes;
    Producto arreglo_productos[200];
    int cantidad_productos;
};

#endif /* ALMACEN_H */

