/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 13 de mayo de 2024, 11:39 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "BibliotecaColaGenerica.h"
#include "PilaGenerica.h"
#include "FuncNumeros.h"

int main(int argc, char** argv) {
    void *cola;
    creaCola(cola,leenum,"numeros.txt");
    imprimir(cola,imprimenum,"reporteNoOrdenado.txt");
    ordenaCola(cola,cmpnum);
    imprimir(cola,imprimenum,"reporteOrdenado.txt");
    return 0;
}

