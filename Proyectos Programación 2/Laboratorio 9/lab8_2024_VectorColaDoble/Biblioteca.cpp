/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.cpp
 * Author: margo
 * 
 * Created on 20 de junio de 2024, 7:50
 */

#include "Biblioteca.h"
#include "Estante.h"
#include "Novela.h"
#include "Revista.h"
#include "Enciclopedia.h"
#include "Nodo.h"

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::cargar() {
    ifstream arch("estantes2.csv", ios::in);
    if (not arch.is_open()){
        cout<<"error con la lectura"<<endl;
        exit(1); 
    }
    //H,1,20
    char tip;
    int id;
    double cap;
    while(true){
        arch>>tip;
        Estante contiene;
        if(arch.eof()) break;
        arch.get();
        arch>>id;
        arch.get();
        arch>>cap;
        contiene.setear(tip, id, cap);
        AEstante.push_back(contiene);
    }
    int i=0;
    for(auto x:AEstante){
        AEstante[i].impresion();
        i++;
        cout<<endl;
    }
}

void Biblioteca::insertar() {
     ifstream arch("libros3.csv", ios::in);
    if (not arch.is_open()){
        cout<<"error con la lectura"<<endl;
        exit(1); 
    }
     /**
      * R,Historica,52,0.25,2223375,2019,3
E,ENCICLOPEDIA VIDA SALVAJE DEL MUNDO,480,2,17974,2020
E,ATLAS ILUSTRADO - MATEMATICAS E INFORMATICA,252,1.5,46903,2022
N,Rimas y leyendas,104,0.4,Gustavo Adolfo Becquer
      * 
      */
     Libro *libro=new class Libro;
     char tip;
     int i=0, li=0;
     while(true){
         arch>>tip;
         if (arch.eof()) break;
         arch.get();
         li++;
         cout<<i<<endl;
         cout<<li<<endl;
         agregarMemoriaSetear(tip,libro, arch);
         if (i<AEstante.size()){
             if (AEstante[i]+=libro){
                 
             }else{
                 i++;
             }
         }
     }
}
void Biblioteca::agregarMemoriaSetear(char tip, Libro*& libro, ifstream& arch) {
    switch(tip){
        case 'R':
            libro = new class Revista;
            break;
        case 'N':
            libro = new class Novela;
            break;
        case 'E':
            libro = new class Enciclopedia;
            break;
        default: 
            libro=nullptr;
            break;
    }
    libro->lee(arch);
}

void Biblioteca::baja() {
    for(auto x:AEstante){
        x--;
        cout<<"primero"<<endl;
    }
}

void Biblioteca::imprimir() {
    ofstream arch("vectorCola.txt",ios::out);
    if (not arch.is_open()){
        cout<<"error con la impreison"<<endl;
        exit(1);
    }
    arch<<"impresion libros"<<endl;
    for(auto x:AEstante){
        arch<<x;
        arch<<endl;
    }
}
