/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 01:08 AM
 */

#ifndef NODO_H
#define NODO_H
#include <fstream>
using namespace std;
#include "ListaDoble.h"
#include "AlumnoNotas.h"
class Nodo {
private:
    class AlumnoNotas dato;
    class Nodo *siguiente;
    class Nodo *anterior;
public:
    Nodo();
    friend class ListaDoble;
};

#endif /* NODO_H */

