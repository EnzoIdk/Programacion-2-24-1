/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   CursoAlumno.cpp
 * Author: Enzo
 * 
 * Created on 25 de junio de 2024, 04:39 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "CursoAlumno.h"

CursoAlumno::CursoAlumno() {
    codcur=nullptr;
    vez=1;
    ciclo=0;
}

CursoAlumno::CursoAlumno(const CursoAlumno& orig) {
}

CursoAlumno::~CursoAlumno() {
    if(codcur!=nullptr) delete codcur;
}

void CursoAlumno::SetVez(int vez) {
    this->vez = vez;
}

int CursoAlumno::GetVez() const {
    return vez;
}

void CursoAlumno::SetNota(int nota) {
    this->nota = nota;
}

int CursoAlumno::GetNota() const {
    return nota;
}

void CursoAlumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double CursoAlumno::GetCreditos() const {
    return creditos;
}

void CursoAlumno::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int CursoAlumno::GetCiclo() const {
    return ciclo;
}

void CursoAlumno::SetCodcur(const char *cad) {
    if(codcur!=nullptr) delete codcur;
    codcur=new char[strlen(cad)+1];
    strcpy(codcur,cad);
}

void CursoAlumno::GetCodcur(char *cad) const {
    if(codcur==nullptr) cad[0]=0;
    else strcpy(cad,codcur);
}

void CursoAlumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int CursoAlumno::GetCodigo() const {
    return codigo;
}

void CursoAlumno::lee(ifstream &arch){
    int aux;
    char cad[10],car;
    arch>>aux;
    if(arch.eof()) return;
    SetCodigo(aux);
    arch.get();
    arch.getline(cad,10,',');
    SetCodcur(cad);
    arch>>creditos>>car>>ciclo>>car>>nota;
    arch.get();
}

void CursoAlumno::muestra(){
    cout<<codigo<<' '<<codcur<<' '<<ciclo<<endl;
}

void CursoAlumno::imprime(ofstream& arch){
    arch<<codigo<<setw(3)<<' '<<codcur<<setw(4)<<' '<<ciclo<<setw(10)<<nota<<
            setw(7)<<vez<<setw(10)<<creditos;
}
