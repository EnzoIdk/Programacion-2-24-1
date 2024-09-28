/* 
 * Proyecto: LAB07_PREG01_CLASES
 * File:   Pedido.h
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 10 de junio de 2022, 8:06
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "Cliente.h"
#include "Pedido.h"

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetNombre(const char *cad);
    void GetNombre(char *cad) const;
    
    void imprimirFecha(ofstream &arch) const;
    
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int dni;
    int fecha;
};

#endif /* PEDIDO_H */

