/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Punteros genéricos con asignación de memoria exacta
 * Created on 21 de abril de 2024, 10:33 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "funciones.h"

int main(int argc, char** argv) {
    void *ventas,*productos,*clientes;
    leeVentas(ventas);
    imprimeVentas(ventas);
    leeProductos(productos);
    imprimeProductos(productos);
    leeClientes(clientes);
    imprimeClientes(clientes);
    liquidaVentas(clientes,ventas,productos);
    return 0;
}

