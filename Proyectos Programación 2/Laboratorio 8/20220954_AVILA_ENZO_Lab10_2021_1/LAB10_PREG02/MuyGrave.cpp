/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   MuyGrave.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 03:19 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Infraccion.h"
#include "MuyGrave.h"

MuyGrave::MuyGrave() {
    meses=0;
    puntos=0;
}

void MuyGrave::SetMeses(int meses) {
    this->meses = meses;
}

int MuyGrave::GetMeses() const {
    return meses;
}

void MuyGrave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int MuyGrave::GetPuntos() const {
    return puntos;
}

void MuyGrave::lee(ifstream &arch,int cod){
    Infraccion::lee(arch,cod);
    arch>>puntos;
    arch.get();
    arch>>meses;
}

void MuyGrave::imprime(ofstream &arch){
    Infraccion::imprime(arch);
    double desc=0;
    arch<<setw(10)<<desc<<setw(10)<<puntos<<setw(10)<<meses<<endl;
}

