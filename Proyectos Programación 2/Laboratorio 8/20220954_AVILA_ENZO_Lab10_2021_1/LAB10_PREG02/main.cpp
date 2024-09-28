/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 02:07 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "LFalta.h"
using namespace std;

int main(int argc, char** argv) {
    LFalta lf1,lf2;
    lf1.leer("RegistroDeFaltas1.csv");
    lf2.leer("RegistroDeFaltas2.csv");
    lf1.unir(lf2);
    lf1.imprimir("Reporte.txt");
    return 0;
}

