/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 9 de junio de 2024, 09:22 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Lista.h"
#include "Persona.h"
int main(int argc, char** argv) {
    class Lista lista;
    lista.crear("personal.csv");
    lista.imprimir("ReporteDePersonas.txt");
    lista.imprimeR("ReporteDePersonasV2.txt");
    return 0;
}

