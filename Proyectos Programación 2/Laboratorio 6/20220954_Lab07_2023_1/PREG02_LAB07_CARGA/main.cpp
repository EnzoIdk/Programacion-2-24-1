/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 05:38 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>   
#include "Funciones.h"
#include "Alumno.h"
#include "AlumnoNota.h"

using namespace std;

int main(int argc, char** argv) {
    Alumno lalumnos[100];
    AlumnoNota lnotas[200];
    cargaralumnos(lalumnos);
    carganotas(lnotas);
    actualizanotas(lalumnos,lnotas);
    imprimealumnos(lalumnos);
    return 0;
}

