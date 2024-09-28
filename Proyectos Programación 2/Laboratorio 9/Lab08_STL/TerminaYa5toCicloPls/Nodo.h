/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 09:18 PM
 */

#ifndef NODO_H
#define NODO_H
#include <fstream>
using namespace std;
#include "Libro.h"
#include "Lista.h"
class Nodo {
private:
    class Libro *plibro;
    class Nodo *sig;
    class Nodo *ant;
public:
    Nodo();
    friend class Lista;
};

#endif /* NODO_H */

