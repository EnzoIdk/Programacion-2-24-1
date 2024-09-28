/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Lista.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 18:55
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
    //REVISAR
}

//GETTERS Y SETTERS
void Lista::SetPeso(double peso) {
    this->peso = peso;
}

double Lista::GetPeso() const {
    return peso;
}

//METODOS
void Lista::operator =(const class Lista& orig){
    this->SetPeso(orig.GetPeso());
    ini=orig.ini;
}

void Lista::insertar(class Libro* temp){
    class Nodo * nuevo=new class Nodo, * aux=ini, * ant=nullptr;
    nuevo->plibro=temp;
    while(aux){
        ant=aux;
        aux=aux->sig;
    }
    if(ant==nullptr) ini=nuevo;
    else ant->sig=nuevo;
    //
    peso+=temp->GetPeso();
}

void Lista::baja(int aa){
    class Nodo * aux=ini;
    while(aux){
        aux->plibro->actualiza(aa);
        aux=aux->sig;
    }
}

void Lista::muestra(ofstream& arch){
    class Nodo * aux=ini;
    while(aux){
        aux->plibro->imprime(arch);
        arch<<endl;
        aux=aux->sig;
    }
}

//FUNCIONES
