/* 
 * File:   Presencial.cpp
 * Author: ramir
 * 
 * Created on 5 de junio de 2024, 02:45 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Presencial.h"

Presencial::Presencial() {
    recargo = 0.0;
    total = 0.0;
}

Presencial::Presencial(const Presencial& orig) {
}

Presencial::~Presencial() {
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
//202119153,MENDOZA/ARIAS/HENRY,4,19.5,10
void Presencial::lee(ifstream &archBol){
    Alumno::lee(archBol);
    archBol>>recargo;
    archBol.get();
}

void Presencial::imprime(ofstream &archRep){
    archRep<<fixed<<setprecision(2);
    Alumno::imprime(archRep);
    archRep<<right<<setw(21)<<total<<endl;
}