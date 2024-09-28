/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tercera.cpp
 * Author: Enzo
 * 
 * Created on 25 de junio de 2024, 04:40 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Tercera.h"
#include "CursoAlumno.h"

Tercera::Tercera() {
    porcentaje=0;
}

Tercera::Tercera(const Tercera& orig) {
}

Tercera::~Tercera() {
}

void Tercera::SetPorcentaje(double porcentaje) {
    this->porcentaje = porcentaje;
}

double Tercera::GetPorcentaje() const {
    return porcentaje;
}

void Tercera::actualiza(){
    CursoAlumno::SetVez(3);
    if(CursoAlumno::GetCreditos()<=3) porcentaje=100;
    else porcentaje=50;
}

void Tercera::imprime(ofstream& arch){
    CursoAlumno::imprime(arch);
    arch<<setw(10)<<porcentaje<<endl;
}