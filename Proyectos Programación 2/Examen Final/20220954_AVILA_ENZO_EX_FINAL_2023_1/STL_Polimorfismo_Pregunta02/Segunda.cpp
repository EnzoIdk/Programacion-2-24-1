/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Segunda.cpp
 * Author: Enzo
 * 
 * Created on 25 de junio de 2024, 04:39 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Segunda.h"
#include "CursoAlumno.h"

Segunda::Segunda() {
}

Segunda::Segunda(const Segunda& orig) {
}

Segunda::~Segunda() {
}

void Segunda::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Segunda::GetCreditos() const {
    return creditos;
}

void Segunda::actualiza(){
    CursoAlumno::SetVez(2);
    if(CursoAlumno::GetCreditos()<=3) SetCreditos(1.0);
    else SetCreditos(1.5);
}

void Segunda::imprime(ofstream& arch){
    CursoAlumno::imprime(arch);
    arch<<setw(10)<<creditos<<endl;
}