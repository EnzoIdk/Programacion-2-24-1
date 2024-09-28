/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: margo
 * 
 * Created on 11 de junio de 2024, 18:34
 */

#include "Lista.h"
#include "Nodo.h"
#include "FIchas.h"
#include <iostream>
#include <cstring>
using namespace std;
Lista::Lista() {
    cabeza=nullptr;
    
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
    if (cabeza!=nullptr) delete cabeza;
}

void Lista::lecturaFichar(ifstream&arch) {
    class Nodo *nodo=new class Nodo;
    char *id=new char[3]{};
    char tipo;
    //F1      C      8      15
    int col, fil;
    while(true){
        arch>>id;
        if (arch.eof()) return;
        arch>>tipo;
        nodo->asignaMemoria(tipo);
        arch>>fil;
        arch>>col;
        nodo->rellenaFicha(id, tipo, col, fil);
        insertarLista(nodo);
    }
}

void Lista::insertarLista(Nodo *&nodo) {
    
    if (cabeza==nullptr){
        cabeza = new class Nodo;
        *cabeza = *nodo;
        cabeza->siguiente=nullptr;
    }else{
        class Nodo*p=cabeza;
        class Nodo *ant=nullptr;
        while(p){
            ant=p;
            p=p->siguiente;
        }
        p=new class Nodo;
        *p=*nodo;
        p->siguiente=nullptr;
        ant->siguiente=p;
    }
}

void Lista::imprimeLista(ofstream &arch) {
    class Nodo*p=cabeza;
    while(p){
       p->ptr->impresion(arch);
       p=p->siguiente;
    }
}

void Lista::actualizar(ifstream&arch) {
    //F1     R     19
    char ficha[3]{};
    char mov;
    int cantid;
    while(true){
        arch>>ficha;
        if (arch.eof()) break;
        arch>>mov;
        arch>>cantid;
        aplicarMov(cabeza, mov, ficha, cantid);
    }
}
void Lista::aplicarMov(class Nodo*nod, char mov, char *fich, int cant){
    if (nod==nullptr) return;
    char id[3]{};
    nod->ptr->GetIdficha(id);
    if (strcmp(id, fich)==0) {
        nod->ptr->movimientos(mov, cant);
    }else{
        aplicarMov(nod->siguiente, mov, fich, cant);
    }
}