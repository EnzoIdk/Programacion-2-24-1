/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 8 de mayo de 2024, 01:38 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "Pregunta01Examen01PunterosMultiples.h"
#include "Pregunta02Examen01PunterosGenericos.h"

#include "ColaConEnteros.h"
#include "ColaConProductos.h"
#include "ColaGenerica.h"

using namespace std;

int main(int argc, char** argv) {
    char **codigoDelProducto;
    int **fechaClienteCantidad;
    void *productos;
    void *cola;
    
    cargarPedidos(fechaClienteCantidad,codigoDelProducto,"Pedidos.csv");
    pruebaDeCargaDePedidos(fechaClienteCantidad,codigoDelProducto,"PruebaPedidos.txt");
    cargarProductos(productos,"Productos.csv");
    pruebaDeCargaDeProductos(productos);
    cargaEnteros(cola,leenumero,"numeros.txt");
    mostrarEnteros(cola,imprimenumero,"reporte.txt");
    procesarPedidos(fechaClienteCantidad,codigoDelProducto,productos);
    reporteDePedidos(productos,"reportefinal.txt");
    
    return 0;
}

