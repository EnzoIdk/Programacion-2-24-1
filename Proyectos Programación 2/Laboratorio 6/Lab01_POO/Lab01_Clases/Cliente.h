/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 09:00 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include "LibroPedido.h"

using namespace std;

class Cliente {
private:
    int dni;
    char *nombre;
    LibroPedido librosSolicitados[30];
    int cantLibros;
    double montoTotal;
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetMontoTotal(double montoTotal);
    double GetMontoTotal() const;
    void SetCantLibros(int cantLibros);
    int GetCantLibros() const;
    void SetNombre(const char*);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    bool operator <<(class LibroPedido &ped);
    void operator ++(void); /*como prefijo*/
    void ImprimirPedidos(ofstream &);
};

bool operator >>(ifstream &,Cliente &cli);
void operator <<(ofstream &,Cliente &cli);

#endif /* CLIENTE_H */

