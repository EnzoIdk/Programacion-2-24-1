/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 4 de abril de 2024, 11:28 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "funciones.h"

int main(int argc, char** argv) {

    ifstream archClientes,archProductos,archPedidos;
    ofstream archRepClientes,archRepProductos;
    struct Cliente clientes[200];
    struct Producto productos[200];
    struct Pedido pedidos[600];
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,"Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProductos,"Productos.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepClientes,"Clientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepProductos,"Productos.txt");
    probarSobrecargas(archClientes,archProductos,archPedidos,archRepClientes,
            archRepProductos,clientes,productos,pedidos);

    return 0;
}

