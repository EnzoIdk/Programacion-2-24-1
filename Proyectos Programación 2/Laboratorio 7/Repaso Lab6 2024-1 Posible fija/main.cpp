/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 30 de mayo de 2024, 19:19
 */

#include "Biblioteca.h"

int main(int argc, char** argv) {

    class Biblioteca biblioteca;
    
    biblioteca.cargar_libros();
    biblioteca.cargar_estantes();
    biblioteca.posicionar_libros();
    biblioteca.mostrar_datos();
        
    return 0;
}

