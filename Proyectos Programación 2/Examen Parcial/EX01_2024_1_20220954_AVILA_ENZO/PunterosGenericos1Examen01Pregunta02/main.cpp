
/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 14 de mayo de 2024, 08:03 AM
 */

#include <iostream>

using namespace std;

#include "AperturaDeArchivos.h"
#include "PunteroVoid.h"
#include "MuestraVoid.h"
#include "PunterosMultiples1Examen01Pregunta01.h"

int main(int argc, char** argv) {
    char **ventasLibroCodigo,***libro;
    int **ventasDniFechaPuntaje;
    void *ventas;
    cargarVentas(ventasLibroCodigo,ventasDniFechaPuntaje,"Ventas.csv");
    cargaLibro(libro,"Libros.csv");
    cargaventas(libro,ventas);
    actualizaventas(ventasDniFechaPuntaje,ventasLibroCodigo,ventas);
    muestraventas(ventas);
    return 0;
}

