/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 8 de mayo de 2024, 09:02 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "Pregunta01Examen01PunterosMultiples.h"

using namespace std;

int main(int argc, char** argv) {
    char **codigoDelProducto;
    int **fechaClienteCantidad;
    cargarPedidos(fechaClienteCantidad,codigoDelProducto,"Pedidos.csv");
    pruebaDeCargaDePedidos(fechaClienteCantidad,codigoDelProducto,"PruebaPedidos.txt");
    return 0;
}

