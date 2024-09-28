/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 * mapa con string y una clase
 * Created on 29 de junio de 2024, 05:07 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Procesa.h"        

using namespace std;

int main(int argc, char** argv) {
    Procesa pro;
    pro.carga();
    pro.muestra();
    pro.cargaEstante();
    pro.cargaLibros();
    pro.muestraLibros();
    return 0;
}

