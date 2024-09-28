/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 4 de abril de 2024, 04:47 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>  
#include <cstring>

using namespace std;

#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "funciones.h"

int main(int argc, char** argv) {
    
    ifstream archClientes,archProductos,archPedidos;
    ofstream archC,archP;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProductos,"Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,"Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archC,"Clientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archP,"Productos.txt");
    struct Cliente clientes[200];
    struct Producto productos[200];
    struct Pedido pedidos[600];
    for(int i=0;archClientes>>clientes[i];i++);
    for(int i=0;archProductos>>productos[i];i++);
    for(int i=0;archPedidos>>pedidos[i];i++);
    for(int i=0;strcmp(pedidos[i].CodigoProducto,"XXXXXXX")!=0;i++){
        productos+=pedidos[i];
        clientes+=pedidos[i];
    }
    for(int i=0;clientes[i].dni;i++) archC<<clientes[i];
    for(int i=0;strcmp(productos[i].codigo,"XXXXXXX")!=0;i++) archP<<productos[i];
    return 0;
}

