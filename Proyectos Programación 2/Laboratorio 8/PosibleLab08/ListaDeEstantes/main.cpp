/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 08:19 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Biblioteca.h"
using namespace std;

int main(int argc, char** argv) {
    class Biblioteca biblioteca;
    biblioteca.cargaLibros();
    biblioteca.cargaEstantes();
    biblioteca.posicionarLibros();
    biblioteca.mostrarDatos();
    return 0;
}

