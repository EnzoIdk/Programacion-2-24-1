/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   A.cpp
 * Author: margo
 * 
 * Created on 11 de junio de 2024, 18:29
 */

#include "A.h"
#include "FIchas.h"

A::A() {
}

A::A(const A& orig) {
}

A::~A() {
}

void A::movimientos(char tipo, int cantidad) {
    switch (tipo){
        case 'P':
            SetFila(GetFila()-cantidad);
            break;
        case 'Q':
            SetColumna(GetColumna()+cantidad);
            break;
        case 'R':
            SetFila(GetFila()+cantidad);
            break;
        case 'S':
            SetColumna(GetColumna()-cantidad);
            break;
        default:
            break;
    }
}

void A::impresion(ofstream&arch) {
     FIchas::impresion(arch);
}



