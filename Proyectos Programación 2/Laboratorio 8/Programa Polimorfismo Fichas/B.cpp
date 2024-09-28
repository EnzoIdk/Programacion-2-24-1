/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   B.cpp
 * Author: Enzo
 * 
 * Created on 7 de junio de 2024, 09:09 AM
 */

#include <iomanip>
#include <fstream>
using namespace std;
#include "B.h"

void B::imprime(ofstream &arch){
    char ident[10];
    GetId(ident);
    arch<<"Tipo B: "<<left<<setw(5)<<ident<<right<<setw(5)<<GetFila()<<
            setw(5)<<GetCol()<<endl;
}

//se mueve como alfil, en diagonal
void B::mover(char dir, int cant){
    switch(dir){
        case 'P': //arriba-izquierda
            SetFila(GetFila()-cant);
            SetCol(GetCol()-cant);
            break;
        case 'Q': //arriba-derecha
            SetFila(GetFila()-cant);
            SetCol(GetCol()+cant);
            break;
        case 'R': //abajo-derecha
            SetFila(GetFila()+cant);
            SetCol(GetCol()+cant);
            break;
        case 'S':
            SetFila(GetFila()+cant);
            SetCol(GetCol()-cant);
            break;
    }
}


