/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 13 de mayo de 2024, 09:56 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "PriorityQueu.h"
#include "FuncionesEnteros.h"
#include "FuncionesRegistro.h"

int main(int argc, char** argv) {
    void *cola1,*cola2;
    crearCola(cola1,leeRegInt,prioridadRegInt,"Datos.txt");
    prueba(cola1,imprimeRegInt,"Reporte1.txt");
    crearCola(cola2,leeRegistro,prioridadRegistro,"Pacientes.csv");
    prueba(cola2,imprimeRegistro,"Reporte2.txt");
    return 0;
}

