/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Leve.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 03:16 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Infraccion.h"
#include "Leve.h"

Leve::Leve() {
    descuento=0;
}

void Leve::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Leve::GetDescuento() const {
    return descuento;
}

void Leve::lee(ifstream &arch,int cod){
    Infraccion::lee(arch,cod);
    arch>>descuento;
}

void Leve::imprime(ofstream &arch){
    Infraccion::imprime(arch);
    int puntos=0,meses=0;
    arch<<setw(10)<<descuento<<setw(10)<<puntos<<setw(10)<<meses<<endl;
}

