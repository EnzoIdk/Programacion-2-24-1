/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Boleta.cpp
 * Author: Enzo
 * 
 * Created on 11 de junio de 2024, 09:36 PM
 */

using namespace std;
#include "Boleta.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

Boleta::Boleta() {
    pboleta=nullptr;
}

Boleta::~Boleta() {
    if(pboleta!=nullptr) delete pboleta;
}

void Boleta::asignaMemoria(char tipo){
    switch(tipo){
        case 'P':
            pboleta=new class Presencial;
            break;
        case 'S':
            pboleta=new class Semipresencial;
            break;
        case 'V':
            pboleta=new class Virtual;
            break;
    }
}

void Boleta::leerDatos(ifstream &arch){
    pboleta->lee(arch);
}

void Boleta::SetNull(){
    pboleta=nullptr;
}

int Boleta::GetCodigo() const{
    return pboleta->GetCodigo();
}

void Boleta::imprimeAlumnos(ofstream &arch){
    pboleta->imprime(arch);
}

int Boleta::GetEscala() const{
    return pboleta->GetEscala();
}

void Boleta::actualizaBoleta(double costoCred){
    pboleta->actualizatotal(costoCred);
}