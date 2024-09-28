/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Medicina_Cantidad.h
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 07:26 PM
 */

#ifndef MEDICINA_CANTIDAD_H
#define MEDICINA_CANTIDAD_H
#include <fstream>
using namespace std;

class Medicina_Cantidad {
private:
    int codigo;
    int cantidad;
public:
    Medicina_Cantidad();
    Medicina_Cantidad(const Medicina_Cantidad& orig);
    virtual ~Medicina_Cantidad();
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void imprimeMedicina(ofstream &arch);
};

    void operator >>(ifstream &arch,class Medicina_Cantidad &dato);

#endif /* MEDICINA_CANTIDAD_H */

