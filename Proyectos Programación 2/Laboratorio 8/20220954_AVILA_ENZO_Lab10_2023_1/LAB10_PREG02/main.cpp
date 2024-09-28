/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author:  Enzo
 *
 * Created on 12 de junio de 2024, 01:44 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Tesoreria.h"
using namespace std;

int main(int argc, char** argv) {
    Tesoreria ABoleta;
    ABoleta.cargaalumnos();
    ABoleta.actualizaboleta();
    ABoleta.imprimeboleta();
    return 0;
}

