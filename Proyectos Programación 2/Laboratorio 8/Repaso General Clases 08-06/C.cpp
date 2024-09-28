/* 
 * File:   C.cpp
 * Author: Lucas
 * 
 * Created on 9 de junio de 2024, 14:10
 */

#include <iostream>
#include <fstream>
using namespace std;
#include <cstring>

#include "C.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
C::C() {

}

C::C(const class C &orig) {

}

C::~C() {

}

//GETTERS Y SETTERS

//METODOS
void C::mover(char direccion, int casillas){
    switch(direccion){
        case 'P':
            SetFila(GetFila()+2);
            SetColumna(GetColumna()+1);
            break;
        case 'S':
            SetFila(GetFila()+1);
            SetColumna(GetColumna()-2);
            break;
        case 'Q':
            SetFila(GetFila()-1);
            SetColumna(GetColumna()+2);
            break;
        case 'R':
            SetFila(GetFila()-2);
            SetColumna(GetColumna()-1);
            break;
    }
}

void C::imprimir(ofstream &arch){
    arch<<"Tipo C: ";
    this->Ficha::imprimirDatos(arch);
//    char idTemp[5];
//    GetId(idTemp);
//    arch<<setw(5)<<idTemp<<setw(5)<<GetFila()<<setw(5)<<GetColumna()<<endl;
}

//FUNCIONES
