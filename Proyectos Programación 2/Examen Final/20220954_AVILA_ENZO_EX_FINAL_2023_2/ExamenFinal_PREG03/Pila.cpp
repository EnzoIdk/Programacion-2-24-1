/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pila.cpp
 * Author: Enzo
 * 
 * Created on 8 de julio de 2024, 03:28 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Pila.h"
#include "Nodo.h"
#include "Furgon.h"
#include "Camion.h"

Pila::Pila() {
    pila=nullptr;
}

Pila::Pila(const Pila& orig) {
}

Pila::~Pila() {
//    void eliminarPila();
}

void Pila::apilar(class Vehiculo* vehiculo){
    class Nodo *nuevoNodo=new class Nodo;
    nuevoNodo->unidad=vehiculo;
    nuevoNodo->sig=pila;
    pila=nuevoNodo;
}

void Pila::imprimir(ofstream &arch){
    class Nodo *rec=pila;
    while(rec){
        rec->unidad->mostrar(arch);
        rec=rec->sig;
    }
}

void Pila::desapilar(string &aux){
    class Nodo *sale=pila;
    if(sale){
        pila=pila->sig;
        aux=sale->unidad->GetPlaca();
        delete sale;
    }
}

void Pila::eliminarPila(){
    class Nodo *rec=pila;
    while(rec){
        class Nodo *sale=rec;
        rec=rec->sig;
        delete sale;
    }
    pila=nullptr;
}

class Vehiculo * Pila::desapilar(){
    class Nodo *sale=pila;
    if(sale){
        Vehiculo *dato=sale->unidad;
        pila=pila->sig;
        delete sale;
        return dato;
    }
    
}