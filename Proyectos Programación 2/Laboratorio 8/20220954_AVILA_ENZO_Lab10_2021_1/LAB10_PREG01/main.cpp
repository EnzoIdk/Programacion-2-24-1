/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 12 de junio de 2024, 02:52 PM
 */

#include <iostream>
#include "LFalta.h"
using namespace std;

int main(int argc, char** argv) {
    LFalta lf1,lf2;
    lf1.leer("RegistroDeFaltas1.csv");
    lf2.leer("RegistroDeFaltas2.csv");
    lf1.imprimir("Reporte1.txt");
    lf2.imprimir("Reporte2.txt");
    return 0;
}

