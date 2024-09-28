/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.cpp
 * Author: Jeremy Lopez Galindo
 * 
 * Created on 4 de diciembre de 2023, 08:25 PM
 */

#include "Nota.h"
#include "Primera.h"
#include "Segunda.h"
#include "Tercera.h"

Nota::Nota() {
    pnota = nullptr;
}

Nota::Nota(const Nota& orig) {
    if(orig.pnota->getVez() == 1)pnota = new Primera;
    if(orig.pnota->getVez() == 2)pnota = new Segunda;
    if(orig.pnota->getVez() == 3)pnota = new Tercera;
    *this = orig;
}

Nota::~Nota() {
    if(pnota)delete pnota;
}

void Nota::leer(ifstream& in) {
    int alum, cic, nota;
    char cod[20];
    double cred;
    in>>alum;
    if(in.eof())return;
    in.get();
    in.getline(cod,20,',');
    in>>cred;
    in.get();
    in>>cic;
    in.get();
    in>>nota;
    pnota = new Primera;
    pnota->setCiclo(cic);
    pnota->setCodCurso(cod);
    pnota->setCodigo(alum);
    pnota->setCreditos(cred);
    pnota->setNota(nota);
    pnota->setVez(1);
}

void Nota::operator=(const Nota& otro) {
    char cod[50];
    otro.pnota->getCodCurso(cod);
    pnota->setCodCurso(cod);
    pnota->setCiclo(otro.pnota->getCiclo());
    pnota->setCodigo(otro.pnota->getCodigo());
    pnota->setCreditos(otro.pnota->getCreditos());
    pnota->setNota(otro.pnota->getNota());
    pnota->setVez(otro.pnota->getVez());
}

bool Nota::operator<(const Nota& otro) {
    char cod1[20],cod2[20];
    pnota->getCodCurso(cod1);
    otro.pnota->getCodCurso(cod2);      
    if(pnota->getCodigo() < otro.pnota->getCodigo())return true;
    else if(pnota->getCodigo() == otro.pnota->getCodigo() and strcmp(cod1,cod2) < 0)return true;
    else if(pnota->getCodigo() == otro.pnota->getCodigo() and strcmp(cod1,cod2) == 0 and pnota->getCiclo() < otro.pnota->getCiclo())return true;
    else return false;
}

void Nota::getCurso(char* cad) {
    pnota->getCodCurso(cad);
}

int Nota::getCodigo() {
    return pnota->getCodigo();
}

void Nota::actualizar(const Nota &nota) {
    if(pnota->getVez() == 1){
        delete pnota;
        pnota = new Segunda;
        *this = nota;
        pnota->actualiza();
    }
    else if(pnota->getVez() == 2){
        delete pnota;
        pnota = new Tercera;
        *this = nota;
        pnota->actualiza();
    }
}

void Nota::imprimir(ofstream& out) {
    pnota->imprime(out);
}
