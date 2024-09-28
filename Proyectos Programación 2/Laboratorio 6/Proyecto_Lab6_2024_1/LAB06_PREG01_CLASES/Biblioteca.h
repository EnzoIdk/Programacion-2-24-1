/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.h
 * Author: ISA
 *
 * Created on 24 de mayo de 2024, 10:14 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <fstream>
using namespace std;
#include "Libro.h"
#include "Estantes.h"
class Biblioteca {
private:
    class Estantes estantes[20];
    int cantidad_estantes;
    class Libro libros[100];
    int cantidad_libros;
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void cargar_libros();
    void cargar_estantes();
    void posicionar_libros();
    void mostrar_datos();
};

#endif /* BIBLIOTECA_H */

