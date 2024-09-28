/* 
 * File:   main.cpp
 * Author: aml
 *
 * Created on 12 de junio de 2024, 12:07 PM
 */

#include "Flota.h"

int main(int argc, char** argv) {
    class Flota transporte;
    
    transporte.cargaFlota("Promocion.csv");
    transporte.muestraCarga("ReporteParcial.txt");
    
    transporte.cargaPedidos("Pedidos3.csv");
    transporte.muestraCarga("ReporteFinal.txt");
    
    return 0;
}

