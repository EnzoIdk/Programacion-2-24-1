/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 29 de mayo de 2024, 04:05 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Estante.h"
#include "Libro.h"
using namespace std;

int main(int argc, char** argv) {
    ifstream archLib("Libros.csv",ios::in);
    if(not archLib.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros.csv"<<endl;
        exit(1);
    }
    ifstream archEst("Estantes.csv",ios::in);
    if(not archEst.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Estantes.csv"<<endl;
        exit(1);
    }
    ofstream archRep("ReporteSimple.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteSimple.txt"<<endl;
        exit(1);
    }
    class Estante est;
    class Libro lib;
    archEst>>est;
    while(true){
        archLib>>lib;
        if(archLib.eof()) break;
        est+=lib;
    }
    archRep<<est;
    return 0;
}

