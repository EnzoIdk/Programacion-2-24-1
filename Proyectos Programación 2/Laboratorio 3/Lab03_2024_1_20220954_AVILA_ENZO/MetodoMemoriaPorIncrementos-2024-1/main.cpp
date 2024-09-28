/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani
 *
 * Created on 19 de abril de 2024, 08:14 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "MetodoExactoDeMemoria.h"
#include "AperturaDeArchivos.h"

int main(int argc, char** argv) {
    char ***libros,***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    lecturaDeLibros ("Libros.csv",libros, stock);
    pruebaDeLecturaDeLibros ("ReporteDeLibrosInicial.txt",libros, stock);
    atencionDePedidos ("Pedidos.txt", libros, stock, pedidosClientes, pedidosLibros, pedidosAtendidos);
    pruebaDeLecturaDeLibros ("ReporteDeLibrosFinal.txt", libros, stock);
    ordenarPedidosClientes (pedidosClientes);
    reporteDeEntregaDePedidos ("ReporteDeEntregaDePedidos.txt", pedidosClientes, pedidosLibros,
        pedidosAtendidos);
    return 0;
}

