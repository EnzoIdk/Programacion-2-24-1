/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Semipresencial.cpp
 * Author: Enzo
 * 
 * Created on 28 de mayo de 2024, 04:50 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    total=0;
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}

void Semipresencial::leerDatos(ifstream &arch){
    Alumno::leerDatos(arch);
    arch>>descuento;
    arch.get();
}

void Semipresencial::actualiza(double monto){
    total=monto*GetDescuento()/100;
    Alumno::SetTotal(monto-total);
}

void Semipresencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch<<setw(15)<<'-'<<setw(10)<<Alumno::GetTotal()<<endl;
}