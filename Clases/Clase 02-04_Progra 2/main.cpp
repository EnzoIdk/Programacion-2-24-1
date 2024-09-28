/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: aml
 *
 * Created on 2 de abril de 2024, 08:21 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

#include "funciones.h"
/*
 * Ejercicio con memoria exacta, mañana se hará por incremento
 */
int main(int argc, char** argv) {
    int *codigo;
    char **nombre,***cursos;
    cargarAlumnos(codigo,nombre,"Alumnos.csv");
    cargarCursos(codigo,cursos,"Cursos.csv");
    reporte(codigo,nombre,cursos);
    
    return 0;
}

