/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Lista.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 09:26 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Lista.h"
#include "Nodo.h"

Lista::Lista() {
    peso=0;
    ini=nullptr;
    fin=nullptr;
}


Lista::~Lista() {
    eliminar();
}

void Lista::setPeso(double peso) {
    this->peso = peso;
}

double Lista::getPeso() const {
    return peso;
}

void Lista::insertar(class Libro *auxLib){
    class Nodo *nuevoNodo;
    class Nodo *rec=ini,*anterior=nullptr;
    nuevoNodo=new class Nodo;
    nuevoNodo->plibro=auxLib;
//    if(ini==nullptr){
//        ini=nuevoNodo;
//        fin=nuevoNodo;
//    }
//    else{
//        nuevoNodo->ant=fin;
//        fin->sig=nuevoNodo;
//        fin=nuevoNodo;
//    }
    while(rec){
        if(rec->plibro->GetPeso()>nuevoNodo->plibro->GetPeso()) break;
        anterior=rec;
        rec=rec->sig;
    }
    nuevoNodo->sig=rec;
    nuevoNodo->ant=anterior;
    if(rec==nullptr) fin=nuevoNodo;
    if(anterior!=nullptr) anterior->sig=nuevoNodo;
    else ini=nuevoNodo;
    peso+=auxLib->GetPeso();
}

void Lista::imprimeLista(ofstream &arch){
    class Nodo *rec=ini;
    while(rec){
        rec->plibro->imprime(arch);
        rec=rec->sig;
    }
    arch<<endl;
}

void Lista::actualizaLista(){
    class Nodo *rec=ini;
    while(rec){
        rec->plibro->actualiza();
        rec=rec->sig;
    }
}

void Lista::eliminar(){
    class Nodo *sale;
    while(ini){
        sale=ini;
        ini=ini->sig;
        delete sale;
    }
    ini=nullptr;
    fin=nullptr;
}