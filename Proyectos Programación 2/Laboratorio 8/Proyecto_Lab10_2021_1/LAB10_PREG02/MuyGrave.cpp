/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MuyGrave.cpp
 * Author: ISA
 * 
 * Created on 6 de junio de 2024, 04:00 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "MuyGrave.h"

MuyGrave::MuyGrave() {
    meses = 0;
    puntos = 0;
}

MuyGrave::MuyGrave(const MuyGrave& orig) {
}

MuyGrave::~MuyGrave() {
}
void MuyGrave::operator=(const MuyGrave& orig){
    Infraccion::operator =(orig);
    meses = 0;
    puntos = 0;
}
void MuyGrave::SetMeses(int meses) {
    this->meses = meses;
}

int MuyGrave::GetMeses() const {
    return meses;
}

void MuyGrave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int MuyGrave::GetPuntos() const {
    return puntos;
}

bool MuyGrave::lee(ifstream &arch, int cod) {
    bool encontrado = Infraccion::lee(arch, cod);
    if (encontrado) {
        arch >> puntos;
        arch.get();
        arch >> meses;
        arch.get();
    }
    return encontrado;
}

void MuyGrave::imprime(ofstream &arch) {
    arch << setw(10) << 0.00 << setw(10) << puntos << setw(10) << meses << endl;
}