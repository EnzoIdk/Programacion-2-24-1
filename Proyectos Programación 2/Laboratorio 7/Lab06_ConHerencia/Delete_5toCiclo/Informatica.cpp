/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Informatica.cpp
 * Author: Enzo
 * 
 * Created on 30 de mayo de 2024, 10:32 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Informatica.h"

Informatica::Informatica() {
    curso=nullptr;
}

Informatica::~Informatica() {
    if(curso!=nullptr) delete curso;
}

void Informatica::SetCurso(const char *cur) {
    if(curso!=nullptr) delete curso;
    curso=new char[strlen(cur)+1];
    strcpy(curso,cur);
}

void Informatica::GetCurso(char *cur) const {
    if(curso==nullptr) cur[0]=0;
    else strcpy(cur,curso);
}

void Informatica::leerDatos(ifstream &arch){
    char cur[20];
    Libro::leerDatos(arch);
    arch.get();
    arch.getline(cur,20);
    SetCurso(cur);
}
