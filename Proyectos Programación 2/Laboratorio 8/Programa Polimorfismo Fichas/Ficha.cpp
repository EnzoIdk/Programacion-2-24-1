/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Ficha.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2024, 12:06 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Ficha.h"

Ficha::Ficha() {
    id=nullptr;
}

Ficha::~Ficha() {
    if(id!=nullptr) delete id;
}

void Ficha::SetCol(int col) {
    this->col = col;
}

int Ficha::GetCol() const {
    return col;
}

void Ficha::SetFila(int fila) {
    this->fila = fila;
}

int Ficha::GetFila() const {
    return fila;
}

void Ficha::SetId(const char *ident) {
    if(id!=nullptr) delete id;
    id=new char[strlen(ident)+1];
    strcpy(id,ident);
}

void Ficha::GetId(char *ident) const {
    if(id==nullptr) ident[0]=0;
    else strcpy(ident,id);
}

void Ficha::asigna(char *ident, int f, int c){
    SetId(ident);
    SetFila(f);
    SetCol(c);
}
