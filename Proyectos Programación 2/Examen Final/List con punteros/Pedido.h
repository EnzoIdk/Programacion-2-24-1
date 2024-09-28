/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Enzo
 *
 * Created on 7 de julio de 2024, 10:06 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
using namespace std;

class Pedido {
private:
    int codigo;
    char *nombre;
    int cantidad;
    int dni;
    int fecha;
    double total;
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(const char *cad);
    void GetNombre(char *cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(int cod,ifstream &arch);
    virtual void actualiza()=0;
    virtual void imprime(ofstream &,double,double);
};

#endif /* PEDIDO_H */

