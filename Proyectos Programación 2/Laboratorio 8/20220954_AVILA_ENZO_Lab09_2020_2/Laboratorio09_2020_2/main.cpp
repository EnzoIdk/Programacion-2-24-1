/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 10:42 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "ListaPacientes.h"
using namespace std;

int main(int argc, char** argv) {
    class ListaPacientes lista;
    lista.crealista("AtencionDeCitas.csv");
    lista.imprimelista("Reporte.txt");
    return 0;
}

