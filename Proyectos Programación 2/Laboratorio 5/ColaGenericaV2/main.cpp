/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 3 de mayo de 2024, 12:27 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "BibliotecaColaGenerica.h"
#include "ColaConEnteros.h"

int main(int argc, char** argv) {
    void *cola1,*cola2;
    crearCola("datos.txt",cola1,leeEntero);
    imprimirCola(cola1,imprimeInt,"reporte1.txt");
//    construirCola(cola2);
//    encolar(cola2,desencolar(cola1));
//    imprimirCola(cola2,imprimeInt,"prueba.txt");
//    crearCola("datos2.txt",cola2,leeEntero);
//    imprimirCola(cola2,imprimeInt,"reporte2.txt");
    return 0;
}

