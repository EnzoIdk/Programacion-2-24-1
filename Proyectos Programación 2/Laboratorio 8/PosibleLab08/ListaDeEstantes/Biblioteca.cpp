/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Enzo
 * 
 * Created on 13 de junio de 2024, 08:34 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Biblioteca.h"
#include "EstanteHorizontal.h"
#include "EstanteVertical.h"
#include "Libro.h"
#include "Estante.h"
#include "Novela.h"
#include "Enciclopedia.h"

Biblioteca::Biblioteca(){
    numLibros=0;
}

Biblioteca::~Biblioteca(){
    for(int i=0;i<numLibros;i++){
        delete libros[i];
    }
}

void Biblioteca::cargaLibros(){
    ifstream arch("Libros2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros2.csv"<<endl;
        exit(1);
    }
    char tipo;
    class Libro *auxLibro;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        asignarMemoria(auxLibro,tipo);
        auxLibro->leerLib(arch);
        libros[numLibros]=auxLibro;
        numLibros++;
    }
}

void Biblioteca::cargaEstantes(){
    ifstream arch("Estantes2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Estantes.csv"<<endl;
        exit(1);
    }
    listaEst.crear(arch);
}

void Biblioteca::mostrarDatos(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    arch<<setprecision(2)<<fixed;
    listaEst.imprimir(arch);
    listaEst.imprimirLinea(arch,80,'=');
    arch<<"Informacion de todos los libros: "<<endl;
    arch<<"Cantidad de Libros Total: "<<numLibros<<endl;
    for(int i=0;i<numLibros;i++){
        libros[i]->imprimirLib(arch);
    }
    listaEst.imprimirLinea(arch,80,'=');
}

void Biblioteca::setNumLibros(int numLibros) {
    this->numLibros = numLibros;
}

int Biblioteca::getNumLibros() const {
    return numLibros;
}

void Biblioteca::asignarMemoria(class Libro *&aux, char tipo){
    switch(tipo){
        case 'N':
            aux=new class Novela;
            break;
        case 'E':
            aux=new class Enciclopedia;
            break;
    }
}

void Biblioteca::posicionarLibros(){
    listaEst.posicionarLibros(libros,numLibros);
}