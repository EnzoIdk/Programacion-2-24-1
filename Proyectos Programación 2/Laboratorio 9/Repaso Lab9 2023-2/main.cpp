/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 11:58
 */

#include "Flota.h"

int main(int argc, char ** argv) {
    
    class Flota unidades;
    
    unidades.cargaFlota("Vehiculos.csv");
    unidades.muestraCarga("ReporteParcial.txt");
    
    unidades.cargaPedidos("Pedidos3.csv");
    unidades.muestraCarga("ReporteFinal.txt");
    
    return 0;
}

