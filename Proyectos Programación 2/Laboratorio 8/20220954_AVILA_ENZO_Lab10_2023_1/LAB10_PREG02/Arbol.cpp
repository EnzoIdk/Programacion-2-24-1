/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: Enzo
 * 
 * Created on 11 de junio de 2024, 09:49 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Arbol.h"
#include "Boleta.h"

Arbol::Arbol() {
    raiz=nullptr;
}

Arbol::~Arbol() {
}

void Arbol::crear(ifstream& arch){
    char tipo;
    class Boleta dato;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        dato.asignaMemoria(tipo);
        dato.leerDatos(arch);
        insertarR(raiz,dato);
        dato.SetNull();
    }
}

//ABB 
void Arbol::insertarR(class Nodo *&arbol,const class Boleta &dato){
    if(arbol==nullptr){
        arbol=new class Nodo;
        arbol->dboleta=dato;
        return;
    }
    if(arbol->dboleta.GetCodigo()>dato.GetCodigo())
        insertarR(arbol->izq,dato);
    else
        insertarR(arbol->der,dato);
}

void Arbol::mostrarEnOrden(ofstream &arch){
    arch<<left<<setw(10)<<"Codigo"<<setw(40)<<"Nombre"<<setw(8)<<"Escala"
           <<setw(10)<<"Creditos"<<setw(12)<<"Licencia"<<setw(15)<<"Total"<<endl;
    imprimirLinea(arch,90,'-');
    mostrarEnOrdenRec(arch,raiz);
}

void Arbol::mostrarEnOrdenRec(ofstream &arch, class Nodo *raiz){
    if(raiz){
        mostrarEnOrdenRec(arch,raiz->izq);
        raiz->dboleta.imprimeAlumnos(arch);
        mostrarEnOrdenRec(arch,raiz->der);
    }
}

void Arbol::imprimirLinea(ofstream &arch, int tam, char simb){
    for(int i=0;i<tam;i++) arch.put(simb);
    arch<<endl;
}

void Arbol::cargaEscalas(ifstream &arch){
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

void Arbol::actualizaBoletas(){
    actualizaBoletasR(raiz);
}

void Arbol::actualizaBoletasR(Nodo* nodo){
    //en pre-orden
    if(nodo){
        int numEsc=nodo->dboleta.GetEscala();
        double costoCred=lescala[numEsc-1].GetPrecio();
        nodo->dboleta.actualizaBoleta(costoCred);
        actualizaBoletasR(nodo->izq);
        actualizaBoletasR(nodo->der);
    }
}

