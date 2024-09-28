/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 09:38 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <iterator>
using namespace std;
#include "Biblioteca.h"
#include "Estante.h"
#include "Libro.h"
#include "Novela.h"
#include "Revista.h"
#include "Enciclopedia.h"

Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
    for(int i=0;i<VEstantes.size();i++){
        VEstantes[i].eliminar();
    }
}

void Biblioteca::carga(){
    ifstream arch("Estantes2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Estantes2.csv"<<endl;
        exit(1);
    }
    class Estante auxEst;
    while(true){
        auxEst.leerDatos(arch);
        if(arch.eof()) break;
        bool insertado=false;
        for(vector<class Estante>::iterator it=VEstantes.begin();it!=VEstantes.end();it++){
            if(auxEst.getClase()>=(*it).getClase()){
                VEstantes.insert(it,auxEst);
                insertado=true;
                break;
            }
        }
        if(!insertado) VEstantes.push_back(auxEst);
    }
    ofstream arch2("prueba.txt",ios::out);
    for(int i=0;i<VEstantes.size();i++){
        VEstantes[i].imprimeEst(arch2);
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
        insertarLibro(auxLibro);
    }
}

void Biblioteca::asignarMemoria(class Libro*& auxLib, char tipo){
    switch(tipo){
        case 'N':
            auxLib=new class Novela;
            break;
        case 'E':
            auxLib=new class Enciclopedia;
            break;
        case 'R':
            auxLib=new class Revista;
            break;
    }
}

void Biblioteca::insertarLibro(class Libro* auxLib){
    for(int i=0;i<VEstantes.size();i++){
        if(VEstantes[i].insertar(auxLib)) return;
    }
    delete auxLib;
}

void Biblioteca::baja(){
    for(int i=0;i<VEstantes.size();i++){
        VEstantes[i].actualizarEst();
    }
}

void Biblioteca::muestra(){
    ofstream arch("Reporte.txt",ios::out);
    arch<<"Estantes: "<<endl<<endl;
    for(int i=0;i<VEstantes.size();i++){
        VEstantes[i].imprimeEst(arch);
    }
}