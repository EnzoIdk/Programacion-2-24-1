/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 7 de mayo de 2024, 17:21
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;
#include "Pregunta02Examen01PunterosGenericos.h"
/*
 * recuerda el eof
 * Numero de pedidos -1 
 * los último de arreglo es cero
 */
int main(int argc, char** argv) {

    void *productos;
    cargarProductos(productos, "productos.csv");
    pruebaDeCargaDeProductos(productos);
    return 0;
}

