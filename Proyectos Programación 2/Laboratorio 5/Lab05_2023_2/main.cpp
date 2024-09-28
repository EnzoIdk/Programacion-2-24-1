/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 1 de mayo de 2024, 09:19 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>  
#include <cstdlib>

using namespace std;

#include "PilaConEnteros.h"
#include "PilaConRegistros.h"
#include "FlotaGenerica.h"

int main(int argc, char** argv) {
    int numcamiones;
    double pesomaximo;
    void *flota;
    
    numcamiones=5,pesomaximo=10;
    cargacamiones(flota,numcamiones,pesomaximo,leenumero,calculanumero,"numeros.txt");
    qsort(flota,numcamiones,sizeof(void*),cmpnumero);
    muestracamiones(flota,numcamiones,imprimenumero,"reportenum.txt");
    numcamiones=100,pesomaximo=400;
    cargacamiones(flota,numcamiones,pesomaximo,leeregistro,calcularegistro,"pedidos3.csv");
    qsort(flota,numcamiones,sizeof(void*),cmpregistro);
    muestracamiones(flota,numcamiones,imprimeregistro,"reporteregistro.txt");
    return 0;
}

