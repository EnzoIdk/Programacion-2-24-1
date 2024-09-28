/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Enzo
 *
 * Created on 29 de mayo de 2024, 04:05 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <fstream>
using namespace std;
#include "Estante.h"
#include "Libro.h"
class Biblioteca {
private:
    class Estante estantes[10];
    int cantidad_estantes;
    class Libro libros[10];
    int cantidad_libros;
public:
    Biblioteca();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetCantidad_estantes(int cantidad_estantes);
    int GetCantidad_estantes() const;
    void cargar_libros();
    void cargar_estantes();
    void posicionar_libros();
    void mostrar_datos();
    void imprimirLinea(ofstream &,int,char);
};

#endif /* BIBLIOTECA_H */

