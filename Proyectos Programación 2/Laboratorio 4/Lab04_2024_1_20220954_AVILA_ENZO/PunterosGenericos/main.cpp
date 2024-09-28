/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 26 de abril de 2024, 08:04 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

#include "PunterosGenericos.h"

#include "MuestraPunteroGenerico.h"
#include "AperturaDeArchivos.h"

using namespace std;

int main(int argc, char** argv) {
    void *clientes,*reserva;
    cargaclientes(clientes);
    creareserva(reserva);
    cargareservar(clientes,reserva);
    reportefinal(reserva);
    return 0;
}

