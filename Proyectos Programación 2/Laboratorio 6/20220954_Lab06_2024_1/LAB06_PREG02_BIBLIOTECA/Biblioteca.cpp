/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Enzo
 * 
 * Created on 29 de mayo de 2024, 04:05 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Biblioteca.h"

Biblioteca::Biblioteca() {
    cantidad_estantes=0;
    cantidad_libros=0;
}

void Biblioteca::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Biblioteca::GetCantidad_libros() const {
    return cantidad_libros;
}

void Biblioteca::SetCantidad_estantes(int cantidad_estantes) {
    this->cantidad_estantes = cantidad_estantes;
}

int Biblioteca::GetCantidad_estantes() const {
    return cantidad_estantes;
}

void Biblioteca::cargar_libros(){
    ifstream archLib("Libros.csv",ios::in);
    if(not archLib.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros.csv"<<endl;
        exit(1);
    }
    while(true){
        archLib>>libros[cantidad_libros];
        if(archLib.eof()) break;
        cantidad_libros++;
    }
}

void Biblioteca::cargar_estantes(){
    ifstream archEst("Estantes.csv",ios::in);
    if(not archEst.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Estantes.csv"<<endl;
        exit(1);
    }
    while(true){
        archEst>>estantes[cantidad_estantes];
        if(archEst.eof()) break;
        cantidad_estantes++;
    }
}

void Biblioteca::posicionar_libros(){
    for(int i=0;i<cantidad_libros;i++){
        for(int j=0;j<cantidad_estantes;j++){
            if(estantes[j]+=libros[i]) break;
            /*se pasa a ver el siguiente libro*/
        }
    }
}

void Biblioteca::mostrar_datos(){
    ofstream archRep("ReporteSimple.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteSimple.txt"<<endl;
        exit(1);
    }
    imprimirLinea(archRep,60,'=');
    archRep<<"Informacion del posicionamiento de Libros"<<endl<<setw(3)<<' '<<
            "en los estantes de la Biblioteca"<<endl;
    imprimirLinea(archRep,60,'=');
    archRep<<"Cantidad de Estantes: "<<cantidad_estantes<<endl;
    for(int i=0;i<cantidad_estantes;i++) archRep<<estantes[i];
    imprimirLinea(archRep,60,'=');
    archRep<<"Informacion de todos los Libros"<<endl;
    archRep<<"Cantidad de Libros Total: "<<cantidad_libros<<endl;
    for(int i=0;i<cantidad_libros;i++) archRep<<libros[i];
    imprimirLinea(archRep,60,'=');
}

void Biblioteca::imprimirLinea(ofstream &arch,int longitud,char simb){
    for(int i=0;i<longitud;i++) arch.put(simb);
    arch<<endl;
}