/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 14 de mayo de 2024, 12:12 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstdlib>
#include "BibGenerica.h"
#include "FunConEnteros.h"
#include "FunConRegistro.h"
using namespace std;

int main(int argc, char** argv) {
    void *cola;
    creacola(cola,leenumero,prioridadnumero,"numeros.txt");
    descargarcola(cola,muestranumero,"Orden.txt");
    return 0;
}

