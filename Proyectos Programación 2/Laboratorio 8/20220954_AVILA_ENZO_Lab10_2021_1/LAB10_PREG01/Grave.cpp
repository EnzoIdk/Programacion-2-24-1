/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Grave.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 03:17 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Infraccion.h"
#include "Grave.h"

Grave::Grave() {
    descuento=0;
    puntos=0;
}

void Grave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int Grave::GetPuntos() const {
    return puntos;
}

void Grave::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Grave::GetDescuento() const {
    return descuento;
}

void Grave::lee(ifstream &arch,int cod){
    Infraccion::lee(arch,cod);
    arch>>descuento;
    arch.get();
    arch>>puntos;
}

void Grave::imprime(ofstream &arch){
    Infraccion::imprime(arch);
    int meses=0;
    arch<<setw(10)<<descuento<<setw(10)<<puntos<<setw(10)<<meses<<endl;
}

