/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 11:51 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "Funciones.h"

int main(int argc, char** argv) {
    class Funciones aux;
    aux.cargarMedicos();
    aux.cargarPacientes();
    aux.cargarCitas();
    aux.actualizarTarifas();
    aux.mostrarDatos();
    return 0;
}

