/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 4 de abril de 2024, 05:26 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "funciones.h"
#define MAX_CLIENTES 200
#define MAX_PRODUCTOS 200
#define MAX_PEDIDOS 600

int main(int argc, char** argv) {
    
    ifstream archClientes,archProductos,archPedidos;
    struct Cliente clientes[MAX_CLIENTES];
    struct Producto productos[MAX_PRODUCTOS];
    struct Pedido pedidos[MAX_PEDIDOS];
    leerClientes(archClientes,clientes);
    leerProductos(archProductos,productos);
    leerPedidos(archPedidos,pedidos,clientes,productos);
    emitirReporte(clientes,productos);
    
    return 0;
}

