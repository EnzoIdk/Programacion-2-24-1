/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Superclase.h
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 11:11 PM
 */

#ifndef SUPERCLASE_H
#define SUPERCLASE_H
#include "Libro.h"
#include "Cliente.h"

class Superclase {
private:
    Libro arrLibros[300];
    Cliente arrClientes[60];
public:
    Superclase();
    Superclase(const Superclase& orig);
    virtual ~Superclase();
    void cargarLibros();
    void cargarClientes();
    void leerPedidos();
    void emitirReporte();
};

int buscarCli(Cliente *arrCli,int dni);
void imprimirLinea(ofstream &arch,int longitud,char simbolo);

#endif /* SUPERCLASE_H */

