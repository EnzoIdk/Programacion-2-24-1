/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: aml
 *
 * Created on 24 de junio de 2024, 09:48 AM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <fstream>
using namespace std;
#include "Arbol.h"
class Biblioteca {
private:
    class Arbol AEstante;
public:
    void carga();
    void muestra();
    void prueba(double);
};

#endif /* BIBLIOTECA_H */

