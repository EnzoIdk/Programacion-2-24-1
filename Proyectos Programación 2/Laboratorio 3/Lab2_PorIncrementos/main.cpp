/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 17 de abril de 2024, 11:50 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "funciones.h"

int main(int argc, char** argv) {
    char ***libros,***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    lecturaDeLibros ("Libros.csv",libros, stock);
    pruebaDeLecturaDeLibros ("ReporteDeLibrosInicial.txt" ,libros, stock);
    atencionDePedidos ("Pedidos.txt", libros, stock, pedidosClientes, pedidosLibros, pedidosAtendidos);
    pruebaDePedidos("Prueba.txt",pedidosClientes);
    pruebaDeLecturaDeLibros ("ReporteDeLibrosFinal.txt", libros, stock);
    reporteDeEntregaDePedidos ("ReporteDeEntregaDePedisos.txt", pedidosClientes, pedidosLibros,
        pedidosAtendidos);
    return 0;
}

