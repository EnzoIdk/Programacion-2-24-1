/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Gandy Margoreth Zinanyuca Huillca
 *RECUER
 * Created on 8 de abril de 2024, 17:06
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#include "AsignacionDinamicaMemoriaExacta.h"
/*
 * 
 */
int main(int argc, char** argv) {

    char ***productos, ***codigoPedidos;
    int *stock, *fechaPedidos, ***dniCantPedidos;
    double *precios;
    
    lecturaProductos("productos.csv", productos, stock,precios);
    pruebaDeLecturaDeProductos("reporteDeProductos.txt", productos, stock,precios);
    lecturaDePedidos("pedidos.csv", fechaPedidos, codigoPedidos, dniCantPedidos);
    pruebaDeLecturaDePedidos("ReporteDePedidos.txt", fechaPedidos, codigoPedidos, dniCantPedidos);
    reporteDeEnvioDePedidos("reporteDeEntregaDePedisos.txt", productos,stock, precios, fechaPedidos,
            codigoPedidos, dniCantPedidos);
    pruebaDeLecturaDeProductos("reproteDeProductosFinal.txt", productos,stock,precios);
    return 0;
}

