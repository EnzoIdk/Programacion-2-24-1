/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.cpp
 * Author: ISA
 * 
 * Created on 24 de mayo de 2024, 10:14 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Estantes.h"
#include "Libro.h"
#include "Espacio.h"
#include "Biblioteca.h"

Biblioteca::Biblioteca() {
    cantidad_estantes = 0;
    cantidad_libros = 0;
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::cargar_libros(){
    ifstream arch("libros.csv",ios::in);
    if(not arch.is_open()){
        cout << "Error en libros.csv" << endl;
        exit(1);
    }
    while(true){
        arch >> libros[cantidad_libros];
        if(arch.eof())break;
        cantidad_libros++;
    }
}
void Biblioteca::cargar_estantes(){
    ifstream arch("estantes.csv",ios::in);
    if(not arch.is_open()){
        cout << "Error en estantes.csv" << endl;
        exit(1);
    }
    while (true) {
        arch >> estantes[cantidad_estantes];
        if (arch.eof())break;
        cantidad_estantes++;
//        break;
    }
}
void Biblioteca::posicionar_libros(){
//    for(int i = 0;i < cantidad_estantes;i++){
//        for(int k = 0;k < cantidad_libros;k++){
//            if(not libros[k].IsColocado()){
//                estantes[i] += libros[k];
//            }
//        }
//    }
//    estantes[0]+=libros[0];
//    estantes[0]+=libros[1];
    for(int i = 0;i < cantidad_libros;i++){
        for(int k = 0;k < cantidad_estantes;k++){
            if(estantes[k]+=libros[i])break;
        }
    }
    
}
void Biblioteca::mostrar_datos(){
    ofstream arch("reporte.txt",ios::out);
    if(not arch.is_open()){
        cout << "Error en reporte.txt" << endl;
        exit(1);
    }
    int i;
    for(i = 0;i < cantidad_estantes;i++)
        arch << estantes[i];
    
    arch << "Informacion de todos los Libros:" << endl;
    arch << "Cantidad de Libros Total: " << cantidad_libros << endl;
    for (i = 0; i < cantidad_libros; i++)
        arch << libros[i];
}