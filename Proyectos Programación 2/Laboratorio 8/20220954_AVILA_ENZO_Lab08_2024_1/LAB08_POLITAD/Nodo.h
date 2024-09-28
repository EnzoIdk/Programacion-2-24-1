/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: alulab14
 *
 * Created on 14 de junio de 2024, 08:06 AM
 */

#ifndef NODO_H
#define NODO_H
#include <fstream>
using namespace std;
#include "Lista.h"
#include "Libro.h"
class Nodo {
private:
    class Libro *plibro;
    class Nodo *sig;
public:
    Nodo();
    friend class Lista;
};

#endif /* NODO_H */

