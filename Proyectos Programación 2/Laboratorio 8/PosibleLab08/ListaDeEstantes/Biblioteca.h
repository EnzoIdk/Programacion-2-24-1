/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 08:34 AM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <fstream>
using namespace std;
#include "ListaEstantes.h"
#include "Libro.h"
#include "Estante.h"
class Biblioteca {
private:
    class ListaEstantes listaEst;
    class Libro *libros[20];
    int numLibros;
    void asignarMemoria(class Libro *&,char);
public:
    Biblioteca();
    virtual ~Biblioteca();
    void cargaLibros();
    void cargaEstantes();
    void mostrarDatos();
    void setNumLibros(int numLibros);
    int getNumLibros() const;
    void posicionarLibros();
};

#endif /* BIBLIOTECA_H */

