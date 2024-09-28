/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   LibroPedido.h
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 09:17 PM
 */

#ifndef LIBROPEDIDO_H
#define LIBROPEDIDO_H
#include "Libro.h"
using namespace std;

class LibroPedido {
private:
    int numPedido;
    char *codLibro;
    double precio;
    bool atendido;
public:
    LibroPedido();
    LibroPedido(const LibroPedido& orig);
    virtual ~LibroPedido();
    void SetAtendido(bool atendido);
    bool IsAtendido() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodLibro(const char*);
    void GetCodLibro(char *) const;
    void SetNumPedido(int numPedido);
    int GetNumPedido() const;
    bool operator >>(class Libro *arr);
};

int buscarLibro(class Libro *arrLib,char *codLibro);

#endif /* LIBROPEDIDO_H */

