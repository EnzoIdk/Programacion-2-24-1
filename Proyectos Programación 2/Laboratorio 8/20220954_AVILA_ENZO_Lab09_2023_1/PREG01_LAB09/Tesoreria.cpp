/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tesoreria.cpp
 * Author: Enzo
 * 
 * Created on 7 de junio de 2024, 10:22 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Tesoreria.h"

void Tesoreria::cargaescalas(){
    ifstream arch("Escalas.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Escalas.csv"<<endl;
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

void Tesoreria::cargaalumnos(){
    ifstream arch("Alumnos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    }
    char tipo;
    int nD=0;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        lboleta[nD].asignaMemoria(tipo);
        lboleta[nD].leeDatos(arch);
        nD++;
    }
}

void Tesoreria::imprimeboleta(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    arch<<left<<setw(10)<<"Codigo"<<setw(40)<<"Nombre"<<setw(8)<<"Escala"<<
            setw(10)<<"Creditos"<<setw(12)<<"Licencia"<<setw(10)<<"Total"<<endl;
    imprimeLinea(arch,120,'=');
    for(int i=0;lboleta[i].hayDato();i++){
        lboleta[i].imprimeBoleta(arch);
    }
}

void Tesoreria::imprimeLinea(ofstream &arch,int tam,char simb){
    for(int i=0;i<tam;i++) arch.put(simb);
    arch<<endl;
}

void Tesoreria::actualizaboleta(){
    int codEsc;
    double costoCred;
    for(int i=0;lboleta[i].hayDato();i++){
        codEsc=lboleta[i].GetEscala();
        costoCred=lescala[codEsc-1].GetPrecio();
        lboleta[i].actualizaBoleta(costoCred);
    }
}
