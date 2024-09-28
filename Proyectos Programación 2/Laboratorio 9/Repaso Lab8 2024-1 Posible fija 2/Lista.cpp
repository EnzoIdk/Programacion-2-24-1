/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Lista.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 21:17
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "Lista.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

Lista::Lista() {
    peso=0;
    ini=nullptr;
}

Lista::Lista(const class Lista &orig) {

}

Lista::~Lista() {
    //
}

//GETTERS Y SETTERS
void Lista::SetPeso(double peso) {
    this->peso = peso;
}

double Lista::GetPeso() const {
    return peso;
}

//METODOS
void Lista::insertar(const class Estante& dato){
    class Nodo * nuevo=new class Nodo, * aux=ini, * ant=nullptr;
    nuevo->estante=dato;
    while(aux){
        ant=aux;
        aux=aux->sig;
    }
    if(ant==nullptr) ini=nuevo;
    else ant->sig=nuevo;
}

bool Lista::agregarLibro(const class NLibro& libro){
    class Nodo * aux=ini;
    while(aux){
        if(aux->estante.insertar(libro)) return true;
        aux=aux->sig;
    }
    return false;
}

void Lista::baja(){
    class Nodo * aux=ini;
    while(aux){
        aux->estante.baja();
        aux=aux->sig;
    }
}

void Lista::muestra(ofstream& arch){
    class Nodo * aux=ini;
    while(aux){
        aux->estante.muestra(arch);
        aux=aux->sig;
    }
}

void Lista::eliminar(){
    class Nodo * aux=ini;
    while(aux){
        ini=ini->sig;
        delete aux;
        aux=ini;
    }
}

//FUNCIONES
