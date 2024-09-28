/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 5 de junio de 2024, 11:56 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

#include "MovimientosEnTablero.h"
int main(int argc, char** argv) {
    class MovimientosEnTablero movEnTab;
    movEnTab.cargar_Y_MoverFichas("Fichas.txt","Movimientos.txt","Reporte.txt");
    return 0;
}

