/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Boleta.cpp
 * Author: Enzo
 * 
 * Created on 7 de junio de 2024, 04:54 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Boleta.h"

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

void Boleta::leeDatos(ifstream& arch) const{
    pboleta->lee(arch); /*polimorfismo*/
}

bool Boleta::hayDato(){
    return pboleta!=nullptr;
}

int Boleta::GetEscala(){
    return pboleta->GetEscala();
}

void Boleta::imprimeBoleta(ofstream& arch){
    pboleta->imprime(arch);
}

void Boleta::actualizaBoleta(double costoCred){
    pboleta->actualizatotal(costoCred);
}