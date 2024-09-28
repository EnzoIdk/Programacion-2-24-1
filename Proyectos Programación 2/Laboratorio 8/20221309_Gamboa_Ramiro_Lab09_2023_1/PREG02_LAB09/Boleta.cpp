/* 
 * File:   Boleta.cpp
 * Author: ramir
 * 
 * Created on 5 de junio de 2024, 02:49 PM
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
    if(pboleta) delete pboleta;
}
/*
S,202123703,GAMARRA/TABORI/PAUL-RONAL,5,20,30
P,202119153,MENDOZA/ARIAS/HENRY,4,19.5,10
V,202318072,RIVERA/MONTERO/GLORIA-OFELIA,3,20,323R33-2
*/
void Boleta::leealumno(ifstream &archBol){
    char tipo;
    
    archBol>>tipo;
    if(archBol.eof()) return;
    archBol.get();
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
    pboleta->lee(archBol);
}

bool Boleta::existe(){
    if(pboleta) return true;
    else return false;
}

void Boleta::imprimealumno(ofstream &archRep){
    pboleta->imprime(archRep);
}

int Boleta::GetEscala(){
    return pboleta->GetEscala();
}

void Boleta::actualizaboleta(double costoXCred){
    pboleta->actualiza(costoXCred);
}