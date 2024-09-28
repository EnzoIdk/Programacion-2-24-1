/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 8 de julio de 2024, 07:40 PM
 */

#include "Biblioteca.h"

int main(int argc, char ** argv) {
    
    class Biblioteca bli;
    
    bli.carga("Estantes3.csv", "Libros31.csv");
    bli.actualiza(2020);
    bli.muestra("Reporte.txt");
    bli.prueba(8, "Prueba.txt");
    
    return 0;
}

