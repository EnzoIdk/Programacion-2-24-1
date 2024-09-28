/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 16 de abril de 2024, 08:39 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "funciones.h"

int main(int argc, char** argv) {
    int *datos;
    leerDatosPorIncremento(datos,"Datos.txt");
    ordenar(datos);
    imprimir(datos);
    return 0;
}

