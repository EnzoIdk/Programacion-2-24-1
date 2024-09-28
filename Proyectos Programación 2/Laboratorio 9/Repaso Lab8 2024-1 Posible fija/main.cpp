/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 18:41
 */

#include "Biblioteca.h"

int main(int argc, char ** argv) {
    
    class Biblioteca bli;
    
    bli.carga("Estantes2.csv");
    bli.llena("Libros3.csv");
    bli.baja();
    bli.muestra("ReporteLibros.txt");
    
    return 0;
}

