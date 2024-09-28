/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CursoAlumno.cpp
 * Author: Jeremy Lopez Galindo
 * 
 * Created on 4 de diciembre de 2023, 08:16 PM
 */

#include <string.h>

#include "CursoAlumno.h"

CursoAlumno::CursoAlumno() {
    ciclo = 0;
    codcur = nullptr;
    codigo = 0;
    creditos = 0;
    nota = 0;
    vez = 0;
}

//CursoAlumno::CursoAlumno(const CursoAlumno& orig) {
//}

CursoAlumno::~CursoAlumno() {
    if(codcur)delete codcur;
}

int CursoAlumno::getCiclo() const {
    return ciclo;
}

void CursoAlumno::getCodCurso(char* cad) const {
    if(codcur == nullptr)cad[0] = 0;
    else strcpy(cad,codcur);
}

int CursoAlumno::getCodigo() const {
    return codigo;
}

double CursoAlumno::getCreditos() const {
    return creditos;
}

int CursoAlumno::getNota() const {
    return nota;
}

int CursoAlumno::getVez() const {
    return vez;
}

void CursoAlumno::setCiclo(int c) {
    ciclo = c;
}

void CursoAlumno::setCodCurso(char* cad) {
    if(codcur)delete codcur;
    codcur = new char[strlen(cad)+1];
    strcpy(codcur,cad);
}

void CursoAlumno::setCodigo(int c) {
    codigo = c;
}

void CursoAlumno::setCreditos(double c) {
    creditos = c;
}

void CursoAlumno::setNota(int n) {
    nota = n;
}

void CursoAlumno::setVez(int v) {
    vez = v;
}

void CursoAlumno::actualiza() {
    //nada aca
}

void CursoAlumno::imprime(ofstream& out) {
    char cod[20];
    getCodCurso(cod);
    out<<setw(15)<<getCodigo()<<setw(10)<<cod<<setw(10)<<getCiclo()<<setw(10)<<getNota()<<setw(10)<<getVez()
            <<setw(10)<<getCreditos();
}
