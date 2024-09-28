/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 2 de mayo de 2024, 12:49
 */

#include "PilaConEnteros.h"
#include "PilaConRegistros.h"
#include "FlotaGenerica.h"

int main(int argc, char** argv) {
    
    int numCamiones;
    double pesoMaximo;
    void * flota;
    
    numCamiones=5;
    pesoMaximo=10;
    
    cargaCamiones(flota, numCamiones, pesoMaximo, leeNumero, calculaNumero, 
            "numeros.txt");
    
    qsort(flota, numCamiones, sizeof(void * ), cmpNumero);
    
    muestraCamiones(flota, numCamiones, imprimeNumero, "ReporteNum.txt");
    
    numCamiones=100;
    pesoMaximo=400;
    
    cargaCamiones(flota, numCamiones, pesoMaximo, leeRegistro, calculaRegistro, 
            "pedidos3.csv");
    
    qsort(flota, numCamiones, sizeof(void * ), cmpRegistro);
    
    muestraCamiones(flota, numCamiones, imprimeRegistro, "ReporteRegistro.txt");
    
    return 0;
}

