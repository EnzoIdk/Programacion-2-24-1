/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 30 de abril de 2024, 7:07
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
#include "FlotaGenerica.h"
#include "PilaConEnteros.h"
#include "funcRegistro.h"
/*
 * 
 */
int main(int argc, char** argv) {

    int numcamiones;
    double pesomaximo;
    void *flota;
    
    ifstream archNumeros("numeros.txt", ios::in);
    if (not archNumeros.is_open()){
        cout<<"error con la apertura del archivo: "<<endl;
        exit(1);
    }
    ofstream archRepNumeros("reporteNumeros.txt", ios::out);
    if (not archRepNumeros.is_open()){
        cout<<"error con la apertura del archivo: "<<endl;
        exit(1);
    }
    ifstream archRegistro("pedidos3.csv", ios::in);
    if (not archRegistro.is_open()){
        cout<<"error con la apertura del archivo: "<<endl;
        exit(1);
    }
    ofstream archRepRegistro("reporteRegistro.txt", ios::out);
    if (not archRepRegistro.is_open()){
        cout<<"error con la apertura del archivo: "<<endl;
        exit(1);
    }
    
    numcamiones=5;
    pesomaximo=10;
    cargacamiones(flota,numcamiones, pesomaximo, leenumero, calculanumero, archNumeros);
     qsort(flota, numcamiones, sizeof(void*), cmpnumero);
    muestracamiones(flota,numcamiones, pesomaximo,imprimenumero, archRepNumeros);
    
    numcamiones=100;
    pesomaximo=400;
    cargacamiones(flota,numcamiones, pesomaximo, leeregistro, calcularegistro, archRegistro);
     qsort(flota, numcamiones, sizeof(void*), cmpRegistro);
    muestracamiones(flota,numcamiones, pesomaximo, imprimeregistro,archRepRegistro);

    return 0;
}

