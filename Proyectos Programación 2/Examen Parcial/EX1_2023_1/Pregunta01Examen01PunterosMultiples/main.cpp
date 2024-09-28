/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 11 de mayo de 2024, 04:35 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "AperturaDeArchivos.h"
#include "Preg1_Funciones_de_cursos_y_alumnos.h"

int main(int argc, char** argv) {
    char ***cursos,***alumnos_nom_mod;
    double *cursos_cred,escalas[5];
    int *alumnos_cod,**alumnos;
    cargarCursosYEscalas(cursos,cursos_cred,escalas,"Cursos.csv","Escalas.csv");
    pruebaDeCargaDeCursos(cursos,cursos_cred,"PruebaCursos.txt");
    cargarAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,"Alumnos.csv");
    pruebaDeCargaDeAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,"PruebaAlumnos.txt");
    return 0;
}

