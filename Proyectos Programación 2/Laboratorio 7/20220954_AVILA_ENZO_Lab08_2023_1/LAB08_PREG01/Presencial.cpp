/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Presencial.cpp
 * Author: Enzo
 * 
 * Created on 28 de mayo de 2024, 04:29 PM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
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

void Presencial::leerDatos(ifstream &arch){
    Alumno::leerDatos(arch);
    arch>>recargo;
    arch.get(); /*salto de linea*/
}

void Presencial::actualiza(double monto){
    total=monto*GetRecargo()/100;
    Alumno::SetTotal(monto+total);
}

void Presencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch<<setw(15)<<'+'<<setw(10)<<Alumno::GetTotal()<<endl;
}