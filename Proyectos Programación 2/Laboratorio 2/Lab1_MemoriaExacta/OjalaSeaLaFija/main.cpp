/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 11 de abril de 2024, 10:44 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "funciones.h"

int main(int argc, char** argv) {

    char ***libros,***codigoPedidos;
    int *stock,*codClientePed;
    double *precios;
    
    leerLibros("Libros.csv",libros,stock,precios);
    mostrarLibros("PruebaLibros.txt",libros,stock,precios);
    leerPedidos("Pedidos.txt",codigoPedidos,codClientePed);
//    mostrarPedidos("PruebaPedidos.txt",codigoPedidos,codClientePed);
    
    return 0;
}

