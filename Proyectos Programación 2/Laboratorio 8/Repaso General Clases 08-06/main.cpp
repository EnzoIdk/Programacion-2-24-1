/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 8 de junio de 2024, 18:33
 */

#include "Tablero.h"

int main(int argc, char** argv) {
    
    class Tablero tablero;
    
    tablero.leerFichas("Fichas.txt");
    tablero.imprimirFichas("Inicial.txt");
    
    tablero.leerMovimientos("Movimientos.txt");
    tablero.imprimirFichas("Final.txt");
    
    return 0;
}

