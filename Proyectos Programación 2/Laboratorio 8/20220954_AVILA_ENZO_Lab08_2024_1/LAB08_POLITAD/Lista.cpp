/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 08:06 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Lista.h"
#include "Nodo.h"

Lista::Lista() {
    peso=0;
    ini=nullptr;
}

Lista::~Lista() {
    elimina();
}

void Lista::elimina(){
    class Nodo *sale=ini;
    while(ini){
        sale=ini;
        ini=ini->sig;
        delete sale;
    }
    ini=nullptr;
}

int Lista::insertarLibro(Libro*& libro,double capacidad){
    //si no hay espacio lo descarta
    if(capacidad<peso+libro->GetPeso()){
        return 0;
    }
    else{
        class Nodo *rec=ini,*ant=nullptr,*nuevoNodo;
        nuevoNodo=new class Nodo;
        nuevoNodo->plibro=libro;
        while(rec){
            ant=rec;
            rec=rec->sig;
        }
        nuevoNodo->sig=rec;
        if(ant!=nullptr) ant->sig=nuevoNodo;
        else ini=nuevoNodo;
        peso+=libro->GetPeso();
        return 1;
    }
}

void Lista::actualizarLista(){
    class Nodo *rec=ini;
    while(rec){
        rec->plibro->actualiza();
        rec=rec->sig;
    }
}

void Lista::imprimeLista(ofstream &arch){
    class Nodo *rec=ini;
    while(rec){
        rec->plibro->imprime(arch);
        rec=rec->sig;
    }
}