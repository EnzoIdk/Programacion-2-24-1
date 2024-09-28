/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: aml
 * 
 * Created on 24 de junio de 2024, 09:48 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"
#include "NEstante.h"
#include "NLibro.h"

void Biblioteca::carga(){
    ifstream archEst("Estantes3.csv",ios::in);
    if(not archEst.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Estantes3.csv"<<endl;
        exit(1);
    }
    ifstream archLib("Libros31.csv",ios::in);
    if(not archLib.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros31.csv"<<endl;
        exit(1);
    }
    while(true){
        class NEstante auxEst;
        class NLibro auxLib;
        auxEst.leerEst(archEst);
        if(archEst.eof()) break;
        for(int i=0;i<10;i++){
            auxLib.leerLib(archLib);
            auxEst.agregarAEst(auxLib);
        }
        AEstante.insertar(auxEst);
    }
}

void Biblioteca::muestra(){
    ofstream archRep("Reporte.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    archRep<<setprecision(2)<<fixed;
    AEstante.mostrar(archRep);
}

void Biblioteca::prueba(double peso){
    ofstream arch("Prueba.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Prueba.txt"<<endl;
        exit(1);
    }
    AEstante.probar(peso,arch);
}