/* 
 * File:   B.cpp
 * Author: Lucas
 * 
 * Created on 9 de junio de 2024, 14:10
 */

#include <iostream>
#include <fstream>
using namespace std;
#include <cstring>

#include "B.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
B::B() {

}

B::B(const class B &orig) {

}

B::~B() {

}

//GETTERS Y SETTERS

//METODOS
void B::mover(char direccion, int casillas){
    switch(direccion){
        case 'P':
            SetFila(GetFila()+casillas);
            SetColumna(GetColumna()-casillas);
            break;
        case 'S':
            SetFila(GetFila()-casillas);
            SetColumna(GetColumna()-casillas);
            break;
        case 'Q':
            SetFila(GetFila()+casillas);
            SetColumna(GetColumna()+casillas);
            break;
        case 'R':
            SetFila(GetFila()-casillas);
            SetColumna(GetColumna()+casillas);
            break;
    }
}

void B::imprimir(ofstream &arch){
    arch<<"Tipo B: ";
    this->Ficha::imprimirDatos(arch);
//    char idTemp[5];
//    GetId(idTemp);
//    arch<<setw(5)<<idTemp<<setw(5)<<GetFila()<<setw(5)<<GetColumna()<<endl;
}

//FUNCIONES
