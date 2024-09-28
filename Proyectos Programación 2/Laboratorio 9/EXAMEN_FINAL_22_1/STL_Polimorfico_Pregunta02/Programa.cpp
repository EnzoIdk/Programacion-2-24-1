/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Programa.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 12:41 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Programa.h"
#include "NProductos.h"
Programa::Programa() {
}

Programa::Programa(const Programa& orig) {
}

Programa::~Programa() {
}

void Programa::cargaproductos(){
    class NProductos naux;
    ifstream arch("Productos4.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Productos4.csv"<<endl;
        exit(1);
    }
    while(true){
        naux.leeProductos(arch);
        if(arch.eof()) break;
        vproductos.push_back(naux);
    }
}

void Programa::muestraproductos(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    for(int i=0;i<vproductos.size();i++){
        vproductos[i].imprimeProductos(arch);
    }
}