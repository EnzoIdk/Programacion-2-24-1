/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   B.cpp
 * Author: margo
 * 
 * Created on 11 de junio de 2024, 18:29
 */

#include "B.h"

B::B() {
}

B::B(const B& orig) {
}

B::~B() {
}

void B::movimientos(char tipo, int cantidad) {
    switch (tipo){
        case 'P':
            SetColumna(GetColumna()-cantidad);
            SetFila(GetFila()-cantidad);
            break;
        case 'Q':
            SetFila(GetFila()-cantidad);
            SetColumna(GetColumna()+cantidad);
            break;
        case 'R':
            SetFila(GetFila()+cantidad);
            SetColumna(GetColumna()+cantidad);
            break;
        case 'S':
            SetFila(GetFila()+cantidad);
            SetColumna(GetColumna()-cantidad);
            break;
        default:
            break;
    }
}

void B::impresion(ofstream&arch) {
    FIchas::impresion(arch);

}


