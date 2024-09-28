/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Semipresencial.cpp
 * Author: Enzo
 * 
 * Created on 11 de junio de 2024, 08:07 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    total=0;
    descuento=0;
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

void Semipresencial::lee(ifstream &arch){
    Alumno::lee(arch);
    arch>>descuento;
    arch.get();
}

void Semipresencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch<<setw(22)<<total<<endl;
}

void Semipresencial::actualizatotal(double costoCred){
    double monto;
    monto=costoCred*GetCreditos();
    total=descuento*monto/100;
    Alumno::SetTotal(monto-total);
}