/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductoEntregado.h
 * Author: alulab14
 *
 * Created on 22 de mayo de 2024, 10:35 AM
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H
using namespace std;
class ProductoEntregado {
public:
    ProductoEntregado();
    ProductoEntregado(const char*,double=0.0);
    virtual ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(const char*);
    void GetCodigo(char*) const;
private:
    char *codigo;
    double precio;
};

#endif /* PRODUCTOENTREGADO_H */

