/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   C.cpp
 * Author: Enzo
 * 
 * Created on 7 de junio de 2024, 09:41 AM
 */

#include <iomanip>
#include <fstream>
using namespace std;
#include "C.h"

void C::imprime(ofstream &arch){
    char ident[10];
    GetId(ident);
    arch<<"Tipo C: "<<left<<setw(5)<<ident<<right<<setw(5)<<GetFila()<<
            setw(5)<<GetCol()<<endl;
}

void C::mover(char dir,int cant){
    switch(dir){
        case 'P':
            SetFila(GetFila()-2);
            SetCol(GetCol()+1);
            break;
        case 'Q':
            SetFila(GetFila()+1);
            SetCol(GetCol()+2);
            break;
        case 'R':
            SetFila(GetFila()+2);
            SetCol(GetCol()-1);
            break;
        case 'S':
            SetFila(GetFila()-1);
            SetCol(GetCol()-2);
            break;
    }
}