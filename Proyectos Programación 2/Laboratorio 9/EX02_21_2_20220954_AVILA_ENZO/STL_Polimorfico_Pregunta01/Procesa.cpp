/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Procesa.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 02:44 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Libro.h"
#include "NUsuario.h"
#include "Usuario.h"
#include "Procesa.h"
#include "NodoCola.h"

void Procesa::Carga(){
    CargaLibros("Libros2.csv");
    CargaUsuarios("Usuarios2.csv");
    LeeSolicitudes("SolicitudDePrestamos2.csv");
}

void Procesa::CargaLibros(const char* nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Libro auxLibro;
    while(true){
        auxLibro.leelibros(arch);
        if(arch.eof()) break;
        llibros.push_back(auxLibro);
    }
}

void Procesa::CargaUsuarios(const char* nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class NUsuario aux;
    int carne;
    char tipo;
    while(true){
        aux.lee(arch);
        if(arch.eof()) break;
        vusuarios.push_back(aux);
    }
}

void Procesa::LeeSolicitudes(const char* nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int carne;
    char tipo,car,cad[60];
    while(true){
        arch>>carne;
        if(arch.eof()) break;
        arch>>tipo>>car;
        arch.getline(cad,60);
        cola.encolar(cad,carne);
    }
}

void Procesa::Atiende(){
    char cad[60];
    int carne,n=cola.getN();
    for(int i=0;i<n;i++){
        cola.desencolar(cad,carne);
        actualiza(cad,carne);
    }
}

void Procesa::actualiza(char* cad, int carne){
    char aux[60];
    int stock;
    for(list<class Libro>::iterator it=llibros.begin();it!=llibros.end();it++){
        (*it).GetCodigo(aux);
        stock=(*it).GetStock();
        if(strcmp(aux,cad)==0 and stock>0){
            (*it).SetStock(stock-1);
            return;
        }
    }
    //si no hay stock del libro lo devuelve
    cola.encolar(cad,carne);
}

void Procesa::Imprime(){
    ImprimeLibros("ReporteLibros.txt");
    ImprimeCola("ReporteCola.txt");
}

void Procesa::ImprimeLibros(const char* nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for(list<class Libro>::iterator it=llibros.begin();it!=llibros.end();it++){
        (*it).imprimelibro(arch);
    }
}

void Procesa::ImprimeCola(const char* nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char cad[60];
    int carne;
    while(cola.getN()>0){
        cola.desencolar(cad,carne);
        arch<<setw(10)<<"Libro: "<<cad<<endl;
        ImprimeUsuario(carne,arch);
        arch<<endl;
    }
}

void Procesa::ImprimeUsuario(int carne, ofstream& arch){
//    for(vector<class NUsuario>::iterator it=vusuarios.begin();it!=vusuarios.end();it++){
//        if((*it).ObtenerCarne()==carne){
//            (*it).imprime(arch);
//        }
//    }
    for(int i=0;i<vusuarios.size();i++){
        if(vusuarios[i].ObtenerCarne()==carne){
            vusuarios[i].imprime(arch);
        }
    }
}