/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LFalta.cpp
 * Author: ISA
 * 
 * Created on 6 de junio de 2024, 04:08 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "NFalta.h"
#include "LFalta.h"
#define NO_ENCONTRADO -1
LFalta::LFalta() {
    lini = nullptr;
    lfin = nullptr;
}

LFalta::LFalta(const LFalta& orig) {
}

LFalta::~LFalta() { //destruir lista
}

void LFalta::leer(const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if(!arch){
        cout << "Error en: " << nomArch << endl;
        exit(1);
    }
    class Falta dato;
    class NFalta *nuevo;
    int codInf;
    while(true){
        codInf = dato <= arch;
        if(codInf == NO_ENCONTRADO)break;
        nuevo = new class NFalta;
        if(*nuevo <= codInf){
            nuevo->dfalta = dato;
            insertarNodoOrdenado(nuevo);
        }else delete nuevo;
    }
}
void LFalta::insertarNodoOrdenado(class NFalta *nuevo){
    class NFalta *actual = lini,*anterior = nullptr;
    while(actual != nullptr){
        if(actual->dfalta.GetFecha() > nuevo->dfalta.GetFecha())break;
        anterior = actual;
        actual = actual->sig;
    }
    nuevo->sig = actual;
    if(actual == nullptr)lfin = nuevo;
    if(anterior != nullptr)anterior->sig = nuevo;
    else lini = nuevo;
}
void LFalta::unir(class LFalta &concatena){
    lfin->sig = concatena.lini;
    lfin = concatena.lfin;
}
void LFalta::imprimir(const char* nomArch){
    ofstream arch(nomArch, ios::out);
    if (!arch) {
        cout << "Error en: " << nomArch << endl;
        exit(1);
    }
    class NFalta *actual = lini;
    while(actual != nullptr){
        *actual >= arch;
        actual = actual->sig;
    }
}