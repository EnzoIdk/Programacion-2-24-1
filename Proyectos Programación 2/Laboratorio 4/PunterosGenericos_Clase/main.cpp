/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 20 de abril de 2024, 02:23 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "funciones.h"

int main(int argc, char** argv) {
    void *alumnos; /*puntero genérico*/
    cargarAlumnos(alumnos,"Alumnos.csv");
    cargarNotas(alumnos,"CursosNotas.csv");
    calcularPromedios(alumnos);
    probarCarga(alumnos);
    ordenar(alumnos);
    cout<<endl<<endl<<"Alumnos ordenados"<<endl;
    probarCarga(alumnos);
    eliminarDatos(alumnos);
    return 0;
}

