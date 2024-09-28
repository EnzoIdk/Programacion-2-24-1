/* 
 * File:   Semipresencial.cpp
 * Author: ramir
 * 
 * Created on 7 de junio de 2024, 11:10 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    descuento = 0.0;
    total = 0.0;
}

Semipresencial::Semipresencial(const Semipresencial& orig) {
}

Semipresencial::~Semipresencial() {
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
//202123703,GAMARRA/TABORI/PAUL-RONAL,5,20,30
void Semipresencial::lee(ifstream &archAlum){
    Alumno::lee(archAlum);
    archAlum>>descuento;
    archAlum.get();
}

void Semipresencial::imprime(ofstream &archRep){
    Alumno::imprime(archRep);
    archRep<<setw(22)<<total<<endl;
}