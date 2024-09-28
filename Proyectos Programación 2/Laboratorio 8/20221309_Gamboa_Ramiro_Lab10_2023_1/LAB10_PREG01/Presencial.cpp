/* 
 * File:   Presencial.cpp
 * Author: ramir
 * 
 * Created on 7 de junio de 2024, 11:09 AM
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
void Presencial::lee(ifstream &archAlum){
    Alumno::lee(archAlum);
    archAlum>>recargo;
    archAlum.get();
}

void Presencial::imprime(ofstream &archRep){
    Alumno::imprime(archRep);
    archRep<<setw(22)<<total<<endl;
}