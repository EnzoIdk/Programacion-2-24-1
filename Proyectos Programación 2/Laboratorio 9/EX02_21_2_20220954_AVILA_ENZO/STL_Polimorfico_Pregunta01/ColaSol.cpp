/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ColaSol.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 02:12 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ColaSol.h"
#include "NodoCola.h"

ColaSol::ColaSol() {
    inicola=nullptr;
    fincola=nullptr;
    n=0;
}

ColaSol::~ColaSol() {
    
}

void ColaSol::encolar(char *cad,int carne){
    class NodoCola *nuevoNodo=new class NodoCola;
    nuevoNodo->SetCarne(carne);
    nuevoNodo->SetLibsol(cad);
    n++;
    if(inicola==nullptr){
        inicola=nuevoNodo;
        fincola=nuevoNodo;
    }
    else{
        fincola->sig=nuevoNodo;
        fincola=nuevoNodo;
    }
}

void ColaSol::desencolar(char* cad, int& carne){
    class NodoCola *aux;
    if(inicola==nullptr){
        carne=0;
        return;
    }
    n--;
    aux=inicola;
    strcpy(cad,aux->libsol);
    carne=aux->carne;
    if(inicola==fincola){
        inicola=nullptr;
        fincola=nullptr;
    }
    else inicola=inicola->sig;
    delete aux;
}

void ColaSol::setN(int n) {
    this->n = n;
}

int ColaSol::getN() const {
    return n;
}