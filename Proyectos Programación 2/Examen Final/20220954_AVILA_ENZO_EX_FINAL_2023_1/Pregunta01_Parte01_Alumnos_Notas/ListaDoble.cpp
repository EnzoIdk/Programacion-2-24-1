/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ListaDoble.cpp
 * Author: Enzo
 * 
 * Created on 25 de junio de 2024, 01:08 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaDoble.h"
#include "AlumnoNotas.h"
#include "Nodo.h"
ListaDoble::ListaDoble() {
    inicio=nullptr;
    fin=nullptr;
}

//ListaDoble::ListaDoble(const ListaDoble& orig) {
//}

ListaDoble::~ListaDoble() {
}

void ListaDoble::insertar(const class AlumnoNotas &aluNot){
    class Nodo *nuevoNodo=new class Nodo;
    nuevoNodo->dato=aluNot;
    if(inicio==nullptr){
        inicio=nuevoNodo;
        fin=nuevoNodo;
    }
    else{
        fin->siguiente=nuevoNodo;
        nuevoNodo->anterior=fin;
        fin=nuevoNodo;
    }
}

void ListaDoble::imprimirLista(ofstream& arch){
    class Nodo *rec=inicio;
    while(rec){
        rec->dato.imprimeAluNotas(arch);
        rec=rec->siguiente;
    }
}

void ListaDoble::cargarNota(class Nota& nota,int cod){
    class Nodo *rec=inicio;
    while(rec){
        if(rec->dato.obtenerCodigo()==cod){
            rec->dato.insertarNota(nota);
        }
        rec=rec->siguiente;
    }
}