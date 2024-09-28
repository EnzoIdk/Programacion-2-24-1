/* 
 * File:   Boleta.cpp
 * Author: ramir
 * 
 * Created on 7 de junio de 2024, 11:12 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Boleta.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

Boleta::Boleta() {
    pboleta = nullptr;
}

Boleta::Boleta(const Boleta& orig) {
}

Boleta::~Boleta() {
}

void Boleta::asignaMemoria(char tipo){
    switch(tipo){
        case 'P':
            pboleta = new Presencial;
            break;
        case 'S':
            pboleta = new Semipresencial;
            break;
        case 'V':
            pboleta = new Virtual;
            break;
    }
}
    
void Boleta::leerDatos(ifstream &archAlum){
    pboleta->lee(archAlum);
}

void Boleta::SetNull(){
    pboleta = nullptr;
}

int Boleta::GetCodigo() const{
    return pboleta->GetCodigo();
}

void Boleta::imprimealumnos(ofstream &archRep){
    pboleta->imprime(archRep);
}