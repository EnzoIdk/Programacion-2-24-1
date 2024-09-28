/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDoble.cpp
 * Author: margo
 * 
 * Created on 8 de julio de 2024, 18:49
 */

#include "ListaDoble.h"
#include <iostream>
using namespace std;
ListaDoble::ListaDoble() {
    fin=nullptr;
    inicio=nullptr;
}

ListaDoble::ListaDoble(const ListaDoble& orig) {
}

ListaDoble::~ListaDoble() {
}

void ListaDoble::insertarNodo(Alumno&al) {
    Nodo*nuevo=new Nodo;
    if (inicio==nullptr){
        inicio=nuevo;
        inicio->agregarAlumno(al);
    }else{
        Nodo*rec=inicio;
        Nodo*anterior=nullptr;
        nuevo->agregarAlumno(al);
        while(rec){
            cout<<rec->codiogAlumno()<<' '<<al.GetCodigo_alumno()<<endl;
            if (rec->codiogAlumno()>al.GetCodigo_alumno()) break;
            anterior=rec;
            rec=rec->siguiente;
        }
        if (rec==nullptr){
            nuevo->anterior=anterior;
            anterior->siguiente=nuevo;
        }else{
            anterior->siguiente=nuevo;
            nuevo->siguiente=rec;
            nuevo->anterior=anterior;
            rec->anterior=nuevo;
        }
    }
}

void ListaDoble::impresion(ofstream&arch) {
    Nodo*rec=inicio;
    while(rec){
        rec->imprime(arch);
        rec=rec->siguiente;
    }
}

void ListaDoble::agregarNotas(int cod, vector<Nota>&notas) {
    Nodo*rec=inicio;
    while(rec){
        if (rec->codiogAlumno()==cod){
            break;
        }
        rec=rec->siguiente;
    }
    if (rec!=nullptr){//o sea sí se encontró
        rec->dato.agregarNotas(notas);
    }
}


