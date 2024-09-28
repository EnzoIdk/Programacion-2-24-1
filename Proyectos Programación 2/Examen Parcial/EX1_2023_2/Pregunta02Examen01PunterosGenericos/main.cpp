/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 8 de mayo de 2024, 09:32 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "Pregunta02Examen01PunterosGenericos.h"

using namespace std;

int main(int argc, char** argv) {
    void *productos;
    cargarProductos(productos,"Productos.csv");
    pruebaDeCargaDeProductos(productos);
    return 0;
}

