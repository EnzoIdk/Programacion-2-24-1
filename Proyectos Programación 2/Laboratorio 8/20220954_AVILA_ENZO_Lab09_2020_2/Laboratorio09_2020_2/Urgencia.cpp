/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Urgencia.cpp
 * Author: Enzo
 * 
 * Created on 13 de junio de 2024, 10:44 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Urgencia.h"
#include "Paciente.h"

Urgencia::Urgencia() {
}

void Urgencia::SetPorcUrgencia(double porcUrgencia) {
    this->porcUrgencia = porcUrgencia;
}

double Urgencia::GetPorcUrgencia() const {
    return porcUrgencia;
}

void Urgencia::SetPorcSeguro(double porcSeguro) {
    this->porcSeguro = porcSeguro;
}

double Urgencia::GetPorcSeguro() const {
    return porcSeguro;
}

void Urgencia::lee(ifstream &arch){
    Paciente::lee(arch);
    arch>>porcSeguro;
    arch.get();
    arch>>porcUrgencia;
    arch.get();
}

int Urgencia::getPrioridad() const{
    return 2;
}

void Urgencia::imprime(ofstream &arch){
    Paciente::imprime(arch);
    arch<<setw(20)<<porcSeguro<<setw(20)<<porcUrgencia<<endl;
}

bool Urgencia::tieneSeguro() const{
    return true;
}