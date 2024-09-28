/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Enzo
 *
 * Created on 11 de junio de 2024, 09:49 PM
 */

#ifndef ARBOL_H
#define ARBOL_H
#include <fstream>
using namespace std;
#include "Nodo.h"
#include "Escala.h"
#include "Boleta.h"
class Arbol {
private:
    class Nodo *raiz;
    class Escala lescala[10];
    void imprimirLinea(ofstream &,int,char);
    void mostrarEnOrdenRec(ofstream &,class Nodo *);
public:
    Arbol();
    virtual ~Arbol();
    void crear(ifstream &arch);
    void insertarR(class Nodo *&nodo,const class Boleta &dato);
    void mostrarEnOrden(ofstream &arch);
    void cargaEscalas(ifstream &arch);
    void actualizaBoletas();
    void actualizaBoletasR(class Nodo *nodo);
};

#endif /* ARBOL_H */

