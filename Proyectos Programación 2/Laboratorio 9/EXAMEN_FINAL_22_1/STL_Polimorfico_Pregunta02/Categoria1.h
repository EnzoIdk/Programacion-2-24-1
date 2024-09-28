/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Categoria1.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 12:51 AM
 */

#ifndef CATEGORIA1_H
#define CATEGORIA1_H
#include <fstream>
#include "Producto.h"
using namespace std;

class Categoria1:public Producto{
private:
    int prioridad;
    int minimo;
public:
    Categoria1();
    Categoria1(const Categoria1& orig);
    virtual ~Categoria1();
    void SetMinimo(int minimo);
    int GetMinimo() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leeProd(ifstream &arch);
    void imprimeProd(ofstream &arch);
};

#endif /* CATEGORIA1_H */

