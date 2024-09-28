/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C.cpp
 * Author: margo
 * 
 * Created on 11 de junio de 2024, 18:29
 */

#include "C.h"

C::C() {
}

C::C(const C& orig) {
}

C::~C() {
}

void C::movimientos(char tipo, int cantidad) {
    switch (tipo){
        case 'P':
            SetColumna(GetColumna()+1);
            SetFila(GetFila()-2);
            break;
        case 'Q':
            SetFila(GetFila()+1);
            SetColumna(GetColumna()+2);
            break;
        case 'R':
            SetFila(GetFila()+2);
            SetColumna(GetColumna()-1);
            break;
        case 'S':
            SetFila(GetFila()-1);
            SetColumna(GetColumna()-2);
            break;
        default:
            break;
    }
}

void C::impresion(ofstream&arch) {
    FIchas::impresion(arch);
}



