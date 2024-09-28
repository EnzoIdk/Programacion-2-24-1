/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Presencial.cpp
 * Author: Enzo
 * 
 * Created on 7 de junio de 2024, 04:32 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Presencial.h"

Presencial::Presencial() {
    total=0;
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::lee(ifstream &arch){
    Alumno::lee(arch);
    arch>>recargo;
    arch.get();
}

void Presencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch<<setw(22)<<Alumno::GetTotal()<<endl;
}

void Presencial::actualizatotal(double costoCred){
    double monto=costoCred*GetCreditos();
    total=monto*recargo/100;
    Alumno::SetTotal(monto+total);
}