/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 12:33 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Registro.h"
using namespace std;

int main(int argc, char** argv) {
    Registro reg;
    reg.carga();
    reg.procesa();
    reg.muestra();
    return 0;
}

