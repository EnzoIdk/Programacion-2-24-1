/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: aml
 * 
 * Created on 24 de junio de 2024, 09:48 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Arbol.h"
#include "NEstante.h"

Arbol::Arbol() {
    raiz=nullptr;
}

//Arbol::~Arbol() {
//    elimina(raiz);
//}

////se elimina en post orden
//void Arbol::elimina(class NEstante *nodo){
//    if(raiz){
//        elimina(nodo->izq);
//        elimina(nodo->der);
//        delete raiz;
//    }
//}

void Arbol::insertar(const class NEstante &auxEst){
    insertarRec(raiz,auxEst);
}

void Arbol::insertarRec(class NEstante*& nodo,const class NEstante& auxEst){
    if(nodo==nullptr){
        nodo=new class NEstante;
        *nodo=auxEst;
        return;
    }
    if(nodo->GetDisponible()>auxEst.GetDisponible()){
        insertarRec(nodo->izq,auxEst);
    }
    else{
        insertarRec(nodo->der,auxEst);
    }
}

void Arbol::mostrar(ofstream &arch){
    mostrarRec(raiz,arch);
}

void Arbol::mostrarRec(class NEstante* nodo,ofstream &arch){
    if(nodo==nullptr) return;
    mostrarRec(nodo->izq,arch);
    nodo->imprimirEst(arch);
    mostrarRec(nodo->der,arch);
}

void Arbol::probar(double peso, ofstream& arch){
    int colocado=0;
    probarRec(raiz,peso,arch,colocado);
    if(!colocado){
        arch<<"No es posible colocar el libro"<<endl;
    }
}

void Arbol::probarRec(class NEstante* nodo, double peso, ofstream& arch,int &colocado){
    if(nodo==nullptr) return;
    probarRec(nodo->izq,peso,arch,colocado);
    if(nodo->GetDisponible()>peso){
        arch<<"Si hay espacio"<<endl;
        nodo->imprimirEst(arch);
        colocado=1;
        return;
    }
    probarRec(nodo->der,peso,arch,colocado);
}