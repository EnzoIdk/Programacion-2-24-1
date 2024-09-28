/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NFalta.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 03:24 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NFalta.h"
#include "Grave.h"
#include "Leve.h"
#include "MuyGrave.h"

NFalta::NFalta() {
    pfalta=nullptr;
    sig=nullptr;
}

void NFalta::asignarMemoria(int cod){
    switch(cod){
        case 1:
            pfalta=new class Grave;
            break;
        case 2:
            pfalta=new class Leve;
            break;
        case 3:
            pfalta=new class MuyGrave;
            break;
    }
}

void NFalta::buscaInf(int codInf){
    ifstream arch("Infracciones.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Infracciones.csv"<<endl;
        exit(1);
    }
    int cod;
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        if(cod==codInf){
            arch.get();
            pfalta->lee(arch,cod); //polimorfismo
            break;
        }
        else while(arch.get()!='\n');
    }
}

void NFalta::imprimeNodo(ofstream &arch){
    dfalta.imprimeF(arch);
    pfalta->imprime(arch);
}