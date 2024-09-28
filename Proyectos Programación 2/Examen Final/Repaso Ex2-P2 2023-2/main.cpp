/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 7 de julio de 2024, 01:12 PM
 */

#include "Flota.h"

int main(int argc, char ** argv) {
    
    class Flota flota;
    
    flota.cargar_vehiculos("Vehiculos.csv");
    flota.cargar_pedidos("Pedidos4.csv");
    
    flota.mostrar_vehiculos("Reporte.txt");
    
    return 0;
}

