/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 27 de marzo de 2024, 08:23 AM
 */

/* char *nombre[10];              arreglo */

/*PUNTEROS A PUNTEROS    
 La variable apuntada va a contener una dirección de memoria
 Puntero simple:
  int *a;
  a=new int;
  
 Puntero doble (asignación):
  int **a;
  a = new int*;
  *a = new int;         le estoy dando una dirección de memoria a a
  **a=53;
 
 MATRICES DINÁMICAS: un arreglo donde cada elemento apunte a un arreglo
 int **a;
 a=new int *[5];
 a[2]=new int [6];
 a[2][3]= 53;
 
 a[fil][col]
 
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "funciones.h"

int main(int argc, char** argv) {
    int *codigo; /*arreglo de enteros*/
    char **nombre; /*arreglo de cadena de caracteres*/
    char ***cursos; /*arreglo de arreglos de cadena de caracteres*/
    cargarAlumnos(codigo,nombre,cursos,"Alumnos-Cursos.csv");
    reporteAlumnos(codigo,nombre,cursos,"ReporteAlumnos.txt");
    
    return 0;
}

