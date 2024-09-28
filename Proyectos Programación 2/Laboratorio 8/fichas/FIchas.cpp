/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FIchas.cpp
 * Author: margo
 * 
 * Created on 11 de junio de 2024, 18:29
 */

#include "FIchas.h"
#include "A.h"
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
FIchas::FIchas() {
    idficha=nullptr;
    columna=0;
    fila=0;
    tipo=' ';
}

FIchas::FIchas(const FIchas& orig) {
}

FIchas::~FIchas() {
    if (idficha!=nullptr) delete idficha;
    
}

void FIchas::SetColumna(int columna) {
    this->columna = columna;
}

int FIchas::GetColumna() const {
    return columna;
}

void FIchas::SetFila(int fila) {
    this->fila = fila;
}

int FIchas::GetFila() const {
    return fila;
}

void FIchas::SetTipo(char tipo) {
    this->tipo = tipo;
}

char FIchas::GetTipo() const {
    return tipo;
}

void FIchas::SetIdficha(const char* id) {
    if(idficha!=nullptr) delete idficha;
    idficha=new char[strlen(id)+1]{};
    strcpy(idficha, id);
}

void FIchas::GetIdficha(char *id) const {
    if (idficha!=nullptr) strcpy(id,idficha);
    else id[0]=0;
}

void FIchas::SetFicha(char*dt, char tip, int col, int fil) {
    FIchas();
    SetColumna(col);
    SetFila(fil);
    SetIdficha(dt);
    SetTipo(tip);
}

void FIchas::impresion(ofstream&arch){
    arch<<setw(15)<<idficha<<setw(15)<<tipo<<setw(15)<<columna<<setw(15)<<fila<<endl;
}

void FIchas::movimientos(char tip, int cantidad) {
    
}




