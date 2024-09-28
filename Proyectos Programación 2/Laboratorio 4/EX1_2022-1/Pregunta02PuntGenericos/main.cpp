/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 23 de abril de 2024, 11:46 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

int main(int argc, char** argv) {
    void *productos,*pedidos,*clientes;
    cargaproductos(productos);
    cargapedidos(pedidos);
    procesaclientes(productos,pedidos,clientes);
    imprimereporte(clientes);
    return 0;
}

