/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: aml
 *
 * Created on 22 de mayo de 2024, 01:09 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(const char*);
    void GetCodigo(char *) const;
private:
    char *codigo;
    int dni_cliente;
    double precio_producto;
};

bool operator >>(ifstream &arch,class Pedido &ped);

#endif /* PEDIDO_H */

