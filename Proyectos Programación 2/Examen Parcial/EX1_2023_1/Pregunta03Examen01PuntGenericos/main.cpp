/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 12 de mayo de 2024, 12:55 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "PunterosGenericos.h"
#include "AperturaDeArchivos.h"
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    void *alumnoveces;
    char ***cursos,***alumnos_nom_mod;
    int *alumnos_cod,**alumnos;
    cargarAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,"Alumnos.csv");
    CargaCursos(alumnos_cod,alumnoveces,"HistoriaDeNotas.csv");
//    ActualizaVeces(alumnoveces);
//    ImprimeAlumno(alumnoveces);
    return 0;
}

