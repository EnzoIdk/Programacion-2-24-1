
/* 
 * File:   main.cpp
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 24 de mayo de 2024, 10:13 PM
 */
#include <iostream>
#include "Biblioteca.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Biblioteca biblioteca;
    
    biblioteca.cargar_libros();
    cout << '*';
    biblioteca.cargar_estantes();
    cout << '*';
    biblioteca.posicionar_libros();
    biblioteca.mostrar_datos();
    
    return 0;
}

