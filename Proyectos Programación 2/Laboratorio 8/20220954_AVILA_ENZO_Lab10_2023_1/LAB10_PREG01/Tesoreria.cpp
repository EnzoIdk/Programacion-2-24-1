/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tesoreria.cpp
 * Author: Enzo
 * 
 * Created on 12 de junio de 2024, 12:30 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Tesoreria.h"

void Tesoreria::cargaalumnos(){
    ifstream arch("alumnos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    }
    aboleta.crear(arch);
}

void Tesoreria::imprimeboleta(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el arcivo Alumnos.csv"<<endl;
        exit(1);
    }
    aboleta.mostrarEnOrden(arch);
}
