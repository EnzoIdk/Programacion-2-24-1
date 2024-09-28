/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: margo
 * 
 * Created on 11 de junio de 2024, 18:32
 */

#include "Nodo.h"
#include "FIchas.h"
#include "A.h"
#include "B.h"
#include "C.h"

Nodo::Nodo() {
    siguiente=nullptr;
    ptr=nullptr;
    
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
}

void Nodo::asignaMemoria(char tipo) {
    switch (tipo){
        case 'A':
            ptr=new class A;
            break;
        case 'B':
            ptr=new class B;
            break;
        case 'C':
            ptr=new class C;
            break;
        default:
            ptr = nullptr;
            break;
    }
}

void Nodo::rellenaFicha(char*id, char tipo, int col, int fila) {
    ptr->SetFicha(id, tipo, col, fila);
}
Nodo Nodo::operator=(Nodo*no) {
    ptr->SetColumna(no->ptr->GetColumna());
    ptr->SetFila(no->ptr->GetFila());
    char ficha[10]{};
    no->ptr->GetIdficha(ficha);
    ptr->SetIdficha(ficha);
    ptr->SetTipo(no->ptr->GetTipo());
}
