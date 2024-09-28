/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: margo
 *
 * Created on 6 de julio de 2024, 17:34
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Flota.h"
#include "Furgon.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Flota flota;
    flota.cargar_vehiculos();
    flota.cargar_pedidos();
    flota.mostrar_vehiculos();
    return 0;
}

