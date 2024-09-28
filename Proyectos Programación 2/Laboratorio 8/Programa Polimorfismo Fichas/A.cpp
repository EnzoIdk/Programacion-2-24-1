/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   A.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2024, 12:23 PM
 */

#include <iomanip>
#include <iostream>
using namespace std;
#include "A.h"

void A::imprime(ofstream &arch){
    char ident[10];
    GetId(ident);
    arch<<"Tipo A: "<<left<<setw(5)<<ident<<right<<setw(5)<<GetFila()<<
            setw(5)<<GetCol()<<endl;
}

void A::mover(char dir, int cant){
    switch(dir){
        case 'P': //arriba
            SetFila(GetFila()-cant);
            break;
        case 'Q': //derecha
            SetCol(GetCol()+cant);
            break;
        case 'R': //abajo
            SetFila(GetFila()+cant);
            break;
        case 'S': //izquierda
            SetCol(GetCol()-cant);
            break;
    }
}

