/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   MovimientosEnTablero.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2024, 11:58 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "MovimientosEnTablero.h"


void MovimientosEnTablero::cargar_Y_MoverFichas(const char *nombArchFichas,
        const char *nombArchMov, const char *nombArchRep){
    ifstream archFichas(nombArchFichas,ios::in);
    if(not archFichas.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchFichas<<endl;
        exit(1);
    }
    ifstream archMovimientos(nombArchMov,ios::in);
    if(not archMovimientos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchMov<<endl;
        exit(1);
    }
    ofstream archRep(nombArchRep,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchRep<<endl;
        exit(1);
    }
    tablero.leerFichas(archFichas);
    archRep<<"Posiciones iniciales de las fichas: "<<endl;
    tablero.imprimeDatos(archRep);
    archRep<<endl<<endl;
    tablero.leerMovimientos(archMovimientos);
    archRep<<"Posiciones finales: "<<endl;
    tablero.imprimeDatos(archRep);
}

