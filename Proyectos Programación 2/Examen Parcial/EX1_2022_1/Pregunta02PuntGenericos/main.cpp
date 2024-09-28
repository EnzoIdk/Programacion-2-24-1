/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 * Probando por incrementos
 * Created on 7 de mayo de 2024, 09:20 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

#include "MuestraPunteros.h"        
#include "PunterosGenericos.h"

using namespace std;

int main(int argc, char** argv) {
    void *productos,*pedidos,*clientes;
    cargaproductos(productos);
    cargapedidos(pedidos);
    procesaclientes(productos,pedidos,clientes);
    imprimerepfinal(clientes);
    return 0;
}

