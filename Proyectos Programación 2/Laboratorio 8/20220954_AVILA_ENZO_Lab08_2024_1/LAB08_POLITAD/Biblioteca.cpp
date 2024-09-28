/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 08:06 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"
#include "Libro.h"
#include "Novela.h"
#include "Enciclopedia.h"
#include "Revista.h"

Biblioteca::Biblioteca() {
    
}

void Biblioteca::carga(){
    ifstream arch("Estantes2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Estantes2.csv"<<endl;
        exit(1);
    }
    int num=0;
    while(true){
        AEstantes[num].leerEst(arch);
        num++;
        if(arch.eof()) break;
    }
}

void Biblioteca::llena(){
    ifstream arch("Libros3.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros3.csv"<<endl;
        exit(1);
    }
    class Libro *auxLibro;
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        asignarMemoria(auxLibro,tipo);
        auxLibro->lee(arch);
        bool colocado=false;
        for(int i=0;AEstantes[i].GetId();i++){
            if(AEstantes[i].llenarLibro(auxLibro)){
                colocado=true;
                break;
            }
        }
        if(!colocado) delete auxLibro;
    }
}

void Biblioteca::asignarMemoria(class Libro *&aux, char tipo) {
    switch(tipo){
        case 'N':
            aux=new class Novela;
            break;
        case 'E':
            aux=new class Enciclopedia;
            break;
        case 'R':
            aux=new class Revista;
            break;
    }
}


void Biblioteca::baja(){
    for(int i=0;AEstantes[i].GetId();i++){
        AEstantes[i].actualizarVigencia();
    }
}

void Biblioteca::muestra(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    arch<<setprecision(2)<<fixed;
    arch<<"Estantes: "<<endl;
    for(int i=0;AEstantes[i].GetId();i++){
        AEstantes[i].imprimirEstante(arch);
    }
}