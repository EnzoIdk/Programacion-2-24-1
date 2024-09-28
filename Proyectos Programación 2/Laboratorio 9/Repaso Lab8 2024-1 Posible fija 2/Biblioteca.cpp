/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 21:24
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>

#include "Biblioteca.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

Biblioteca::Biblioteca() {

}

Biblioteca::Biblioteca(const class Biblioteca &orig) {

}

Biblioteca::~Biblioteca() {
    lestantes.eliminar();
}

//GETTERS Y SETTERS

//METODOS
void Biblioteca::carga(const char* nomb){
    ifstream arch(nomb, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    class Estante temp;
    //H,3,15
    while(true){
        temp.leer(arch);
        if(arch.eof()) break;
        lestantes.insertar(temp);
    }
}

void Biblioteca::llena(const char* nomb){
    ifstream arch(nomb, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    class NLibro temp;
    //E,LA ENCICLOPEDIA DE LOS DINOSAURIOS,448,2,36225,2018
    while(true){
        temp.leer(arch);
        if(arch.eof()) break;
        if(lestantes.agregarLibro(temp)) continue;
        else temp.eliminar();
    }
}

void Biblioteca::baja(){
    lestantes.baja();
}

void Biblioteca::muestra(const char* nomb){
    ofstream arch(nomb, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    arch<<fixed<<setprecision(2);
    arch<<"Estantes: "<<endl;
    lestantes.muestra(arch);
}

//FUNCIONES
