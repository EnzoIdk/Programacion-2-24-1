/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   LFalta.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 03:29 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "LFalta.h"
#include "Falta.h"
#include "Infraccion.h"
LFalta::LFalta() {
    lini=nullptr;
    lfin=nullptr;
}

LFalta::LFalta(const LFalta& orig) {
}

LFalta::~LFalta() {
}

void LFalta::leer(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Falta datoFal;
    class NFalta *datoNodo;
    int codInf;
    while(true){
        datoFal.leerDatos(arch,codInf);
        datoNodo=new class NFalta;
        if(arch.eof()) break;
//        (*datoNodo).asignarMemoria(codInf/100);
        datoNodo->asignarMemoria(codInf/100);
        datoNodo->buscaInf(codInf);
        datoNodo->dfalta=datoFal;
        insertarNodo(datoNodo);
    }
}

void LFalta::insertarNodo(class NFalta *nuevoNodo){
    class NFalta *rec=lini,*ant=nullptr;
    while(rec){
        if(rec->dfalta.GetFecha()>nuevoNodo->dfalta.GetFecha()) break;
        ant=rec;
        rec=rec->sig;
    }
    nuevoNodo->sig=rec;
    if(rec==nullptr) lfin=nuevoNodo; //si lo recorrió hasta el final, es la cola
    if(ant!=nullptr) ant->sig=nuevoNodo;
    else lini=nuevoNodo;
}

void LFalta::imprimir(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<setprecision(2)<<fixed;
    class NFalta *rec=lini;
    arch<<"Fecha"<<setw(9)<<' '<<"Licencia"<<setw(3)<<' '<<"Placa"<<setw(7)<<
            ' '<<"Infraccion"<<setw(9)<<' '<<"Monto"<<setw(3)<<' '<<"Descuento"<<
            setw(3)<<' '<<"Puntos"<<setw(3)<<' '<<"Meses Susp"<<endl;
    imprimirLinea(arch,120,'-');
    while(rec){
        rec->imprimeNodo(arch);
        rec=rec->sig;
    }
}

void LFalta::imprimirLinea(ofstream &arch,int tam,char simb){
    for(int i=0;i<tam;i++) arch.put(simb);
    arch<<endl;
}