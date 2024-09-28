/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: aml
 *
 * Created on 29 de mayo de 2024, 08:42 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "farmacia.h"

using namespace std;

int main(int argc, char** argv) {
    farmacia ofarma;
    ofarma.cargamedico("Medicos.csv");
    ofarma.leerecetas("Recetas.csv");
    ofarma.imprimirrecetas("Reporte.txt");
    return 0;
}

