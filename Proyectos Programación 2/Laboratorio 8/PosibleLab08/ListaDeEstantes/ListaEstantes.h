/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ListaEstantes.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 09:15 AM
 */

#ifndef LISTAESTANTES_H
#define LISTAESTANTES_H
#include <fstream>
using namespace std;
#include "NodoEst.h"
#include "Estante.h"
#include "Libro.h"
class ListaEstantes {
private:
    class NodoEst *lista;
    void asignarMemoria(class Estante *&,char);
public:
    ListaEstantes();
    virtual ~ListaEstantes();
    void crear(ifstream &);
    void insertar(class Estante *);
    void imprimir(ofstream &);
    void elimina();
    void imprimirLinea(ofstream &,int,char);
    void posicionarLibros(class Libro *libros[20],int numLib);
};

#endif /* LISTAESTANTES_H */

