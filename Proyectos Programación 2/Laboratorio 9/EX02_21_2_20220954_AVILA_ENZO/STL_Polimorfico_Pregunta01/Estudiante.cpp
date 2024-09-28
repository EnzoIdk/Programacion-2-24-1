/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estudiante.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 02:08 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estudiante.h"

Estudiante::Estudiante() {
    celular=0;
}

void Estudiante::SetCelular(int celular) {
    this->celular = celular;
}

int Estudiante::GetCelular() const {
    return celular;
}

void Estudiante::leer(ifstream& arch){
    arch>>celular;
}

void Estudiante::imprime(ofstream& arch){
    Usuario::imprime(arch);
    arch<<"Celular: "<<celular<<endl;
}