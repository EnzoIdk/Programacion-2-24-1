/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Categoria3.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 12:51 AM
 */

#ifndef CATEGORIA3_H
#define CATEGORIA3_H
#include <fstream>
#include "Producto.h"
using namespace std;

class Categoria3:public Producto{
private:
    int prioridad;
    double descuento;
public:
    Categoria3();
    Categoria3(const Categoria3& orig);
    virtual ~Categoria3();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leeProd(ifstream &arch);
    void imprimeProd(ofstream &arch);
};

#endif /* CATEGORIA3_H */

