/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 22 de abril de 2024, 10:22 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

int main(int argc, char** argv) {
    void *productos,*clientes;
    cargaProductos(productos);
    cargaClientes(clientes);
    cargaPedidos(productos,clientes);
//    imprimeReporte(clientes);
    return 0;
}

