/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 14 de mayo de 2024, 08:03 AM
 */

#include <iostream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "AperturaDeArchivos.h"
#include "PunterosMultiples1Examen01Pregunta01.h"

int main(int argc, char** argv) {
    char **ventasLibroCodigo,***libro;
    int **ventasDniFechaPuntaje;
    cargarVentas(ventasLibroCodigo,ventasDniFechaPuntaje,"Ventas.csv");
    pruebaDeCargaDeVentas(ventasLibroCodigo,ventasDniFechaPuntaje,"PruebaVentas.txt");
    cargaLibro(libro,"Libros.csv");
    pruebaDeCargaDeLibros(libro,"PruebaLibros.txt");
    return 0;
}

