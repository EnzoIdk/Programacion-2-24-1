/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Ambulatorio.cpp
 * Author: Enzo
 * 
 * Created on 13 de junio de 2024, 10:44 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Ambulatorio.h"
#include "Paciente.h"

Ambulatorio::Ambulatorio() {
}

void Ambulatorio::SetPorcSeguro(double porcSeguro) {
    this->porcSeguro = porcSeguro;
}

double Ambulatorio::GetPorcSeguro() const {
    return porcSeguro;
}

void Ambulatorio::lee(ifstream &arch){
    Paciente::lee(arch);
    arch>>porcSeguro;
    arch.get();
}

int Ambulatorio::getPrioridad() const{
    return 1;
}

void Ambulatorio::imprime(ofstream &arch){
    Paciente::imprime(arch);
    arch<<setw(20)<<porcSeguro<<endl;
}

bool Ambulatorio::tieneSeguro() const{
    return true;
}