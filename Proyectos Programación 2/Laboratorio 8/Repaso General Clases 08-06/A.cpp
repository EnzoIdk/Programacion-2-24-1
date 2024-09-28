/* 
 * File:   A.cpp
 * Author: Lucas
 * 
 * Created on 9 de junio de 2024, 12:21
 */

#include <iostream>
#include <fstream>
using namespace std;
#include <cstring>

#include "A.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
A::A() {

}

A::A(const class A &orig) {

}

A::~A() {

}

//GETTERS Y SETTERS

//METODOS
void A::mover(char direccion, int casillas){
    switch(direccion){
        case 'P':
            SetFila(GetFila()+casillas);
            break;
        case 'S':
            SetColumna(GetColumna()-casillas);
            break;
        case 'Q':
            SetColumna(GetColumna()+casillas);
            break;
        case 'R':
            SetFila(GetFila()-casillas);
            break;
    }
    
}

void A::imprimir(ofstream &arch){
    arch<<"Tipo A: ";
    Ficha::imprimirDatos(arch);
//    char idTemp[5];
//    GetId(idTemp);
//    arch<<setw(5)<<idTemp<<setw(5)<<GetFila()<<setw(5)<<GetColumna()<<endl;
}

//FUNCIONES
