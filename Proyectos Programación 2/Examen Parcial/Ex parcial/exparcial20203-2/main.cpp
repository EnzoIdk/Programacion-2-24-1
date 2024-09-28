/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 7 de mayo de 2024, 15:54
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;
#include "Pregunta01Examen01PunterosMultiples.h"
/*
 * 
 */
int main(int argc, char** argv) {

    char **codigoDelProducto;
    int **fechaClienteCantidad;
    cargarPedidos(fechaClienteCantidad,codigoDelProducto, "pedidos.csv");
    pruebaDeCrargarDePedidos(fechaClienteCantidad, codigoDelProducto, "pruebaPedidos.txt");
    
    return 0;
}

