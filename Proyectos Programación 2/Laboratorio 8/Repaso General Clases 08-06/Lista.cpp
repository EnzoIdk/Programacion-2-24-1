/* 
 * File:   Lista.cpp
 * Author: Lucas
 * 
 * Created on 8 de junio de 2024, 21:00
 */

#include <iostream>
#include <fstream>
using namespace std;
#include <cstring>

#include "Lista.h"

//CONST Y DEST

Lista::Lista() {
    cabeza=nullptr;
}

Lista::~Lista() {
    this->eliminar();
}

//GETTERS Y SETTERS

//METODOS
void Lista::insertar(class Ficha * ficha){
    class Nodo * aux=cabeza, * ant=nullptr, * nuevo=new class Nodo;
    nuevo->ficha=ficha;
    //INSERTAR
    while(aux){
        ant=aux;
        aux=aux->siguiente;
    }
    if(ant==nullptr) cabeza=nuevo;
    else ant->siguiente=nuevo;
}

void Lista::moverFicha(char * id, char direccion, int casillas){
    class Nodo * aux=cabeza;
    char idTemp[5];
    while(aux){
        aux->ficha->GetId(idTemp);
        if(strcmp(idTemp, id)==0){
            aux->ficha->mover(direccion, casillas);
            break;
        }
        aux=aux->siguiente;
    }
}

void Lista::imprimir(ofstream &arch){
    class Nodo * aux=cabeza;
    while(aux){
        aux->ficha->imprimir(arch);
        aux=aux->siguiente;
    }
}

void Lista::eliminar(){
    class Nodo * aux;
    while(cabeza){
        aux=cabeza;
        cabeza=cabeza->siguiente; //EN LA ULTIMA ITERACION cabeza=nullptr;
        delete aux;
    }
}

//FUNCIONES
