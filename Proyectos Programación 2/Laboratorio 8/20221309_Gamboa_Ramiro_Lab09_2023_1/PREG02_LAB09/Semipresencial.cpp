/* 
 * File:   Semipresencial.cpp
 * Author: ramir
 * 
 * Created on 5 de junio de 2024, 02:46 PM
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
void Semipresencial::lee(ifstream &archBol){
    Alumno::lee(archBol);
    archBol>>descuento;
    archBol.get();
}

void Semipresencial::imprime(ofstream &archRep){
    archRep<<fixed<<setprecision(2);
    Alumno::imprime(archRep);
    archRep<<right<<setw(21)<<Alumno::GetTotal()<<endl;
}

void Semipresencial::actualiza(double costoXCred){
    int monto;
    monto = costoXCred*GetCreditos();
    total = monto*descuento/100;
    Alumno::SetTotal(monto-total);
}