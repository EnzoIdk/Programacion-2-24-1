/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 7 de junio de 2024, 03:50 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
#include "Tesoreria.h"
using namespace std;

int main(int argc, char** argv) {
    Tesoreria OTeso;
    OTeso.cargaescalas();
    OTeso.cargaalumnos();
    OTeso.actualizaboleta();
    OTeso.imprimeboleta();
    return 0;
}

