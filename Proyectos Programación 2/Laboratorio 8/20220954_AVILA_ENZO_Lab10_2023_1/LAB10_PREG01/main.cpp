/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 10 de junio de 2024, 10:09 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;
#include "Tesoreria.h"
int main(int argc, char** argv) {
    Tesoreria ABoleta;
    ABoleta.cargaalumnos();
    ABoleta.imprimeboleta();
    return 0;
}

