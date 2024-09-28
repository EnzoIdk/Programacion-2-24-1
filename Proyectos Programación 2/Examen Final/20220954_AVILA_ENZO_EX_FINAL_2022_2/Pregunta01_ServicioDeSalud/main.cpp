/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 07:22 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;
#include "ServicioDeSalud.h"
int main(int argc, char** argv) {
    class ServicioDeSalud servicioDeSalud;
    servicioDeSalud.leerMedicinas("Medicinas-Preg01.csv");
    servicioDeSalud.imprimirMedicinas("PruebaMedicinas.txt");
    servicioDeSalud.leerConsultas("Consultas-Preg01.csv");
    servicioDeSalud.imprimePacientes("PruebaConsultas.txt");
    servicioDeSalud.totalizar();
    servicioDeSalud.imprimePacientes("PruebaConsultas.total");
    return 0;
}

