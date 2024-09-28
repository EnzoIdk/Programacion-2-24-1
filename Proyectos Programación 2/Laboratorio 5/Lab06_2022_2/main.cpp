/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 2 de mayo de 2024, 10:07 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"

using namespace std;

int main(int argc, char** argv) {
    void *arreglo,*pilaini,*pilafin;
    cargaarreglo(arreglo,cmpnumero,leenumero,"numeros.txt");
    cargapila(pilaini,arreglo);
    muevepila(pilaini,pilafin);
    imprimepila(pilafin,imprimenumero,"repnumeros.txt");
    
    cargaarreglo(arreglo,cmpregistro,leeregistro,"medicinas.csv");
    cargapila(pilaini,arreglo);
    muevepila(pilaini,pilafin);
    imprimepila(pilafin,imprimeregistro,"repmedicinas.txt");
    
    return 0;
}

