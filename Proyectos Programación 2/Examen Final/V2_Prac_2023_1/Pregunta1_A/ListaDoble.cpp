/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDoble.cpp
 * Author: Jeremy Lopez Galindo
 * 
 * Created on 4 de diciembre de 2023, 06:54 PM
 */

#include "ListaDoble.h"

ListaDoble::ListaDoble() {
    inicio = nullptr;
    fin = nullptr;
}

//ListaDoble::ListaDoble(const ListaDoble& orig) {
//}

ListaDoble::~ListaDoble() {
    Nodo *recorrer, *anterior;
    recorrer = inicio;
    anterior = nullptr;
    while(recorrer != nullptr){
        anterior = recorrer;
        recorrer = recorrer->siguiente;
        delete anterior;
    }
}

bool ListaDoble::listaVacia() {
    if(inicio == nullptr)return true;
    else return false;
}

void ListaDoble::insertarLista(Alumno al) {
    Nodo *nuevo, *anterior, *recorrer;
    anterior = nullptr;
    nuevo = new Nodo;
    nuevo->dato.setAlumno(al);
    nuevo->anterior = nullptr;
    nuevo->siguiente = nullptr;
    if(listaVacia()){
        inicio = nuevo;
        fin = nuevo;
    }
    else{
        recorrer = inicio;
        while(recorrer != nullptr){
            if(recorrer->dato.getCodigo() == al.getCodigoAlumno()){
                delete nuevo;
                return;
            }
            if(recorrer->dato.comparar(al)){
                nuevo->siguiente = recorrer;
                recorrer->anterior = nuevo;
                if(anterior == nullptr)inicio = nuevo;
                else{
                    anterior->siguiente = nuevo;
                    nuevo->anterior = anterior;
                }
                break;
            }
            anterior = recorrer;
            recorrer = recorrer->siguiente;
        }
        if(recorrer == nullptr){
            nuevo->anterior = fin;
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }
}

void ListaDoble::insertarNota(Nota nota, int cod) {
    Nodo *recorrer;
    recorrer = inicio;
    while(recorrer != nullptr){
        if(recorrer->dato.getCodigo() == cod){
            recorrer->dato.insertarNota(nota);
            break;
        }
        recorrer = recorrer->siguiente;
    }
}

void ListaDoble::imprimeLista(ofstream& out) {
    Nodo *recorrer;
    recorrer = inicio;
    while(recorrer != nullptr){
        recorrer->dato.imprimir(out);
        recorrer = recorrer->siguiente;
    }
}

void ListaDoble::actualizarNotas() {
Nodo *recorrer;
    recorrer = inicio;
    while(recorrer != nullptr){
        recorrer->dato.actualizar();
        recorrer = recorrer->siguiente;
    }
}

void ListaDoble::totalizar() {
Nodo *recorrer;
    recorrer = inicio;
    while(recorrer != nullptr){
        recorrer->dato.totalizar();
        recorrer = recorrer->siguiente;
    }
}

