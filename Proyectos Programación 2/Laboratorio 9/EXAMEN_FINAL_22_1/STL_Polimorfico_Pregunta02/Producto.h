/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 12:46 AM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <fstream>
using namespace std;

class Producto {
private:
    int codProd;
    char *nombre;
    int stock;
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetNombre(const char *cad);
    void GetNombre(char *cad) const;
    void SetCodProd(int codProd);
    int GetCodProd() const;
    virtual void leeProd(ifstream &arch);
    virtual void imprimeProd(ofstream &arch);
};

#endif /* PRODUCTO_H */

