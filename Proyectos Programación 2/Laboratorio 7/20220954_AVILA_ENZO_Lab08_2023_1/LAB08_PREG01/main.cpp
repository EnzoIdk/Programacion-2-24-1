/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 28 de mayo de 2024, 12:06 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "Tesoreria.h"
int main(int argc, char** argv) {
    class Tesoreria caja;
    caja.cargaescalas("Escalas.csv");
    caja.cargaalumnos("Alumnos.csv");
    caja.actualiza(20);
    caja.imprime("Reporte.txt");
    return 0;
}

