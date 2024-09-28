/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pila.cpp
 * Author: Usuario
 * 
 * Created on 5 de junio de 2024, 01:22 PM
 */

#include "Pila.h"

Pila::Pila() {
    cimaPila=nullptr;
    profundidadPila=0;
}

Pila::~Pila() {
    while(not esPilaVacia())
        desapilar();
    cout<<"Pila: 'Me destruyo'"<<endl;
}

void Pila::apilar(void* dato){
    Nodo *nuevoNodo= new Nodo(dato);
    
    nuevoNodo->siguiente=cimaPila;
    cimaPila=nuevoNodo;
    
    profundidadPila++;
}

bool Pila::esPilaVacia(){
    return profundidadPila==0;
}

void *Pila::cima(){
    if(esPilaVacia())
        return nullptr;
    return cimaPila->dato;
}

void *Pila::desapilar(){
    if(esPilaVacia())
        return nullptr;
    
    Nodo *cimaAux=cimaPila;
    void *datoCima=cima();
    cimaPila=cimaPila->siguiente;
    delete cimaAux;
    
    profundidadPila--;
    return datoCima;
    
}

int Pila::profundidad(){
    return profundidadPila;
}

void *Pila::fondo(){
    if(esPilaVacia())
        return nullptr;
    
    if(profundidadPila==1)
        return cima();
    
    void *datoCima=desapilar();
    void *datoFondo=fondo();
    apilar(datoCima);
    
    return datoFondo;
}

void Pila::apilarAlFondo(void* dato){
    if(esPilaVacia())
        apilar(dato);
    else{
        void *aux=desapilar();
        apilarAlFondo(dato);
        apilar(aux);
    }
}

void Pila::invertir(){
    if(not esPilaVacia()){
        void *aux=desapilar();
        invertir();
        apilarAlFondo(aux);
    }
}

void Pila::duplicar(Pila& pila){
    if(esPilaVacia())
        return;
    
    void *aux=desapilar();
    duplicar(pila);
    pila.apilar(aux);
    
    apilar(aux);
}

void Pila::duplicarDoblemente(Pila& pila){
    if(esPilaVacia())
        return;
    
    void *aux=desapilar();
    duplicarDoblemente(pila);
    pila.apilar(aux);
    pila.apilar(aux);
    
    apilar(aux);
}

void Pila::imprimir(void(*funcionParaImprimir)(void*)){
    if(esPilaVacia()){
        cout<<"Es una pila vacia"<<endl;
        return;
    }
    Pila aux;
    duplicar(aux);
    
    while(true){
        void *dato=aux.cima();
        if(dato)
            funcionParaImprimir(dato);
        if(aux.desapilar()==nullptr){
            cout<<"Fin de la pila"<<endl;
            break;
        }
    }
}

void Pila::concatenar(Pila &pila){
    if(pila.esPilaVacia() or esPilaVacia())
        return;
    
    pila.invertir();
    
    while(not pila.esPilaVacia())
        apilar(pila.desapilar());
}

void Pila::mezclar(Pila& origen1, Pila& origen2){
    origen1.invertir();
    origen2.invertir();
    
    while(not origen1.esPilaVacia() and not origen2.esPilaVacia()){
        apilar(origen1.desapilar());
        apilar(origen2.desapilar());
    }
    
    while(not origen1.esPilaVacia())
        apilar(origen1.desapilar());
    
    while(not origen2.esPilaVacia())
        apilar(origen2.desapilar());
}
