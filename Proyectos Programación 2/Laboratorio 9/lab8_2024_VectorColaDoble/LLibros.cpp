/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LLibros.cpp
 * Author: margo
 * 
 * Created on 20 de junio de 2024, 20:01
 */

#include "LLibros.h"
#include "Nodo.h"
#include "Libro.h"
#include <iostream>
using namespace std;
LLibros::LLibros() {
    cabeza=nullptr;
    fin=nullptr;
    peso=0;
}

LLibros::LLibros(const LLibros& orig) {
    
}

LLibros::~LLibros() {
}

void LLibros::insertarNuevoNodo( Libro*&libro) {
    Nodo*nuevo=new Nodo;
    nuevo->ptr=libro;
    nuevo->sig=nullptr;
    nuevo->ant=nullptr;
    
    if (cabeza==nullptr){
        cabeza=nuevo;
        fin=nuevo;
    }else{
        nuevo->ant=fin;
        fin->sig=nuevo;
        fin=nuevo;
        
    }
    setPeso(libro->GetPeso()+peso);
}

void LLibros::setPeso(double peso) {
    this->peso = peso;
}

double LLibros::getPeso() const {
    return peso;
}

void LLibros::actualizaLibros() {
    Nodo*p=cabeza;
    while(p){
        p->ptr->actualizar();
        p=p->sig;
         cout<<"ga"<<endl;
    }
}

void LLibros::impresionLista(ofstream&arch) {
    Nodo*p=cabeza;
    while(p){
        p->ptr->imprime(arch);
        arch<<endl;
        p=p->sig;
    }
}

