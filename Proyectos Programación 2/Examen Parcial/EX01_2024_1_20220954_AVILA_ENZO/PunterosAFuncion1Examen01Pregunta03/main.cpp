/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani(20220954)
 *
 * Created on 14 de mayo de 2024, 08:06 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "AperturaDeArchivos.h"
#include "PunterosMultiples1Examen01Pregunta01.h"
#include "PunteroVoid.h"
#include "MuestraVoid.h"
#include "PunterosFuncion1Examen01Pregunta03.h"
#include "ColaPrioridadGenerica.h"
#include "Registros.h"

int main(int argc, char** argv) {
    char **ventasLibroCodigo,***libro;
    int **ventasDniFechaPuntaje;
    void *ventas;
    void *ranking;
    cargarVentas(ventasLibroCodigo,ventasDniFechaPuntaje,"Ventas.csv");
    cargaLibro(libro,"Libros.csv");
    cargaventas(libro,ventas);
    actualizaventas(ventasDniFechaPuntaje,ventasLibroCodigo,ventas);
    muestraventas(ventas);
    cargarranking(ranking,crearegistro,ventas);
    muestraranking(ranking,imprimeregistro,"rankings.txt",ventas);
    return 0;
}

