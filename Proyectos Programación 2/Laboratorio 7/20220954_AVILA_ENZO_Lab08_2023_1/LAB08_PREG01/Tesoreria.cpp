/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tesoreria.cpp
 * Author: Enzo
 * 
 * Created on 28 de mayo de 2024, 11:51 PM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
#include "Tesoreria.h"

//Tesoreria::Tesoreria() {
//    lpresencial=nullptr;
//    lsemipresencial=nullptr;
//    lvirtual=nullptr;
//    lescala=nullptr;
//}

//Tesoreria::~Tesoreria() {
//    if(lpresencial!=nullptr) delete lpresencial;
//    if(lsemipresencial!=nullptr) delete lsemipresencial;
//    if(lvirtual!=nullptr) delete lvirtual;
//    if(lescala!=nullptr) delete lescala;
//}

//void Tesoreria::inicializarArreglos(){
//    lpresencial=new class Presencial[100];
//    lsemipresencial=new class Semipresencial[100];
//    lvirtual=new class Virtual[100];
//    lescala=new class Escala[10];
//}

void Tesoreria::cargaescalas(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int cod;
    double precio;
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get();
        arch>>precio;
        lescala[cod-1].SetCodigo(cod);
        lescala[cod-1].SetPrecio(precio);
    }
}

void Tesoreria::cargaalumnos(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char tipo;
    int nP=0,nS=0,nV=0;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        switch(tipo){
            case 'P':
                lpresencial[nP].leerDatos(arch);
                nP++;
                break;
            case 'S':
                lsemipresencial[nS].leerDatos(arch);
                nS++;
                break;
            case 'V':
                lvirtual[nV].leerDatos(arch);
                nV++;
                break;
        }
        /*en todos ya está cargado el 0 como codigo inicial*/
    }
}

void Tesoreria::actualiza(double cred){
    int esc;
    double precioEsc;
    for(int i=0;lpresencial[i].GetCodigo();i++){
        esc=lpresencial[i].GetEscala();
        precioEsc=lescala[esc-1].GetPrecio();
        lpresencial[i].actualiza(cred*precioEsc);
    }
    for(int i=0;lsemipresencial[i].GetCodigo();i++){
        esc=lsemipresencial[i].GetEscala();
        precioEsc=lescala[esc-1].GetPrecio();
        lsemipresencial[i].actualiza(cred*precioEsc);
    }
    for(int i=0;lvirtual[i].GetCodigo();i++){
        esc=lvirtual[i].GetEscala();
        precioEsc=lescala[esc-1].GetPrecio();
        lvirtual[i].actualiza(cred*precioEsc);
    }
}

void Tesoreria::imprime(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<setprecision(2)<<fixed;
    arch<<left<<setw(10)<<"Codigo"<<setw(40)<<"Nombre"<<right<<setw(3)<<
            "Escala"<<right<<setw(12)<<"Licencia"<<setw(8)<<"Total"<<endl;
    imprimeLinea(arch,80,'=');
    for(int i=0;lpresencial[i].GetCodigo();i++)
        lpresencial[i].imprime(arch);
    for(int i=0;lsemipresencial[i].GetCodigo();i++)
        lsemipresencial[i].imprime(arch);
    for(int i=0;lvirtual[i].GetCodigo();i++)
        lvirtual[i].imprime(arch);   
}

void Tesoreria::imprimeLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}