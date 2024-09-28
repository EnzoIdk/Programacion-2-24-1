/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 08:27 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Flota.h"
using namespace std;

int main(int argc, char** argv) {
    class Flota flota;
    flota.cargar_vehiculos();
    flota.cargar_pedidos();
    flota.mostrar_vehiculos();
    return 0;
}

