/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 19:00
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>

#include "Biblioteca.h"
#include "Enciclopedia.h"
#include "Revista.h"
#include "Novela.h"

#define AAMIN 2020
#define MAXLINEA 80

//CONSTRUCTOR, COPIA, DESTRUCTOR

Biblioteca::Biblioteca() {

}

Biblioteca::Biblioteca(const class Biblioteca &orig) {

}

Biblioteca::~Biblioteca() {

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
    //V,2,10
    while(true){
        temp.leerDatos(arch);
        if(arch.eof()) break;
        VEstantes.push_back(temp);
    }
}

void Biblioteca::llena(const char* nomb){
    ifstream arch(nomb, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    class Libro * temp;
    char tipo;
    //N,Cien anios de soledad,210,0.5,Gabriel Garcia Marquez
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        //
        this->asignarLibro(temp, tipo);
        temp->lee(arch);
        this->insertarLibro(temp);
    }
}

void Biblioteca::asignarLibro(class Libro* &temp, char tipo){
    switch(tipo){
        case 'N':
            temp=new class Novela;
            break;
        case 'E':
            temp=new class Enciclopedia;
            break;
        case 'R':
            temp=new class Revista;
            break;
    }
}

void Biblioteca::insertarLibro(class Libro* temp){
//    for(class Estante &estante:VEstantes){
//        if(estante.insertar(temp)) return;
//    }
    for(int i=0; i<VEstantes.size(); i++){
        if(VEstantes[i].insertar(temp)) return;
    }
    delete temp;
}

void Biblioteca::baja(){
//    for(class Estante &estante:VEstantes){
//        estante.baja(AAMIN);
//    }
    for(int i=0; i<VEstantes.size(); i++){
        VEstantes[i].baja(AAMIN);
    }
}

void Biblioteca::muestra(const char* nomb){
    ofstream arch(nomb, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    arch<<fixed<<setprecision(2);
    arch<<"Estantes:"<<endl;
    this->imprimirLinea(arch, '=');
//    for(class Estante &estante:VEstantes){
//        arch<<endl;
//        estante.muestra(arch);
//    }
    for(int i=0; i<VEstantes.size(); i++){
        arch<<endl;
        VEstantes[i].muestra(arch);
    }
}

void Biblioteca::imprimirLinea(ofstream& arch, char car){
    for(int i=0; i<MAXLINEA; i++) arch<<car;
    arch<<endl;
}

//FUNCIONES
