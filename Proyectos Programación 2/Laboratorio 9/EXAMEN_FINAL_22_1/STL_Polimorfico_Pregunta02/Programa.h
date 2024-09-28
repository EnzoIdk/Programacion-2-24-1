/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Programa.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 12:41 AM
 */

#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <fstream>
#include <vector>
#include "NProductos.h"
using namespace std;

class Programa {
private:
    vector <NProductos> vproductos;
public:
    Programa();
    Programa(const Programa& orig);
    virtual ~Programa();
    void cargaproductos();
    void muestraproductos();
};

#endif /* PROGRAMA_H */

