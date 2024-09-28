/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NProductos.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 12:44 AM
 */

#ifndef NPRODUCTOS_H
#define NPRODUCTOS_H
#include <fstream>
#include "Producto.h"
using namespace std;

class NProductos {
private:
    class Producto *prod;
public:
    NProductos();
    NProductos(const NProductos& orig);
    virtual ~NProductos();
    void leeProductos(ifstream &arch);
    void imprimeProductos(ofstream &arch);
};

#endif /* NPRODUCTOS_H */

