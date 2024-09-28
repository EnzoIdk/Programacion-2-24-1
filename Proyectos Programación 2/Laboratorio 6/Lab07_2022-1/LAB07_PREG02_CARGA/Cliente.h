/* 
 * Proyecto: LAB07_PREG01_CLASES
 * File:   Cliente.h
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 10 de junio de 2022, 8:05
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pedido.h"

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    
    void SetTotal(double total);
    double GetTotal() const;
    void SetNumPed(int numPed);
    int GetNumPed() const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetNombre(const char *cad);
    void GetNombre(char *cad) const;
    
    void operator =(const Pedido &ped);
    void operator -=(const Pedido &ped);
    void operator /(double descuento);
    
    void imprimirPedidos(ofstream &arch) const;
private:
    int dni;
    char categoria; // A, B, C
    char *nombre;
    Pedido lped[500];
    int numPed;
    double total;
};

#endif /* CLIENTE_H */

