/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NodoCola.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 02:12 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NodoCola.h"

NodoCola::NodoCola() {
    libsol=nullptr;
    sig=nullptr;
}

NodoCola::~NodoCola() {
    if(libsol!=nullptr) delete libsol;
}

void NodoCola::SetCarne(int carne) {
    this->carne = carne;
}

int NodoCola::GetCarne() const {
    return carne;
}

void NodoCola::SetLibsol(const char *cad) {
    if(libsol!=nullptr) delete libsol;
    libsol=new char[strlen(cad)+1];
    strcpy(libsol,cad);
}

void NodoCola::GetLibsol(char *cad) const {
    if(libsol==nullptr) cad[0]=0;
    else strcpy(cad,libsol);
}
