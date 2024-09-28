/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Nota.cpp
 * Author: Enzo
 * 
 * Created on 25 de junio de 2024, 04:40 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Nota.h"
#include "Primera.h"
#include "Segunda.h"
#include "Tercera.h"

Nota::Nota() {
    pnota=nullptr;
}

Nota::Nota(const Nota& orig) {
    if(orig.pnota->GetVez()==1) pnota=new class Primera;
    if(orig.pnota->GetVez()==2) pnota=new class Segunda;
    if(orig.pnota->GetVez()==3) pnota=new class Tercera;
    this->pnota=orig.pnota;
}

Nota::~Nota() {
//    if(pnota) delete pnota;
}

void Nota::leeNota(ifstream& arch){
    pnota=new class Primera;
    pnota->lee(arch);
    if(arch.eof()) return;
}

void Nota::muestraNota(){
    pnota->muestra();
}

// Sobrecarga necesaria para ordenar según:
// codAlu,codCur,ciclo;
bool Nota::operator <(const Nota& nota){
    char cod1[10],cod2[10];
    pnota->GetCodcur(cod1);
    nota.pnota->GetCodcur(cod2);
    if(pnota->GetCodigo()<nota.pnota->GetCodigo()) return true;
    else if(pnota->GetCodigo()==nota.pnota->GetCodigo() and strcmp(cod1,cod2)<0) return true;
    else if(pnota->GetCodigo()==nota.pnota->GetCodigo() and strcmp(cod1,cod2)==0
            and pnota->GetCiclo()<nota.pnota->GetCiclo()) return true;
    else return false;
}

void Nota::GetCodCur(char* cad) const{
    pnota->GetCodcur(cad);
}

int Nota::GetCodigo() const{
    return pnota->GetCodigo();
}

void Nota::actualizar(const Nota& nota){
    if(pnota->GetVez()==1){
        delete pnota;
        pnota=new class Segunda;
        *this=nota;
        pnota->actualiza();
    }
    else if(pnota->GetVez()==2){
        delete pnota;
        pnota=new class Tercera;
        *this=nota;
        pnota->actualiza();
    }
}

void Nota::operator =(const Nota& nota){
    char cod[10];
    nota.pnota->GetCodcur(cod);
    pnota->SetCodcur(cod);
    pnota->SetCiclo(nota.pnota->GetCiclo());
    pnota->SetCodigo(nota.pnota->GetCodigo());
    pnota->SetCreditos(nota.pnota->GetCreditos());
    pnota->SetNota(nota.pnota->GetNota());
    pnota->SetVez(nota.pnota->GetVez());
}

void Nota::imprimeNota(ofstream &arch){
    pnota->imprime(arch);
}