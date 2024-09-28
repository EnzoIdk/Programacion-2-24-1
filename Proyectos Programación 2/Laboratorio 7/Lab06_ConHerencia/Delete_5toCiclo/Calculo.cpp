/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Calculo.cpp
 * Author: Enzo
 * 
 * Created on 30 de mayo de 2024, 10:32 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Calculo.h"

Calculo::Calculo() {
    num=0;
}

void Calculo::SetNum(int num) {
    this->num = num;
}

int Calculo::GetNum() const {
    return num;
}

void Calculo::leerDatos(ifstream &arch){
    Libro::leerDatos(arch);
    arch>>num;
    arch.get();
}

