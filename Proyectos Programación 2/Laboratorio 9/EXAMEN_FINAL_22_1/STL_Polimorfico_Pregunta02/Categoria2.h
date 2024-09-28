/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Categoria2.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 12:51 AM
 */

#ifndef CATEGORIA2_H
#define CATEGORIA2_H
#include <fstream>
#include "Producto.h"
using namespace std;

class Categoria2:public Producto{
private:
    int prioridad;
    double descuento;
public:
    Categoria2();
    Categoria2(const Categoria2& orig);
    virtual ~Categoria2();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leeProd(ifstream &arch);
    void imprimeProd(ofstream &arch);
};

#endif /* CATEGORIA2_H */

