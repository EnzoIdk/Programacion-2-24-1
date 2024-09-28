/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 12:31 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "Facultad.h"

int main(int argc, char** argv) {
    class Facultad facultad;
    facultad.leerAlumnosNotas("Alumnos-Preg01.csv","Notas-Preg01.csv");
    facultad.imprimirAlumnosNotas("PruebaAlumnosNotas.txt");
    return 0;
}

