/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   AlumnoNota.cpp
 * Author: Enzo
 * 
 * Created on 23 de mayo de 2024, 04:24 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "AlumnoNota.h"
#include "Nota.h"

AlumnoNota::AlumnoNota() {
    codcurso=nullptr;
    codigo=0;
}

AlumnoNota::AlumnoNota(const AlumnoNota& orig) {
}

AlumnoNota::~AlumnoNota() {
    if(codcurso!=nullptr) delete codcurso;
}

void AlumnoNota::SetNota(int nota) {
    this->nota = nota;
}

int AlumnoNota::GetNota() const {
    return nota;
}

void AlumnoNota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int AlumnoNota::GetCiclo() const {
    return ciclo;
}

void AlumnoNota::SetCodcurso(const char *cod) {
    if(codcurso!=nullptr) delete codcurso;
    codcurso=new char[strlen(cod)+1];
    strcpy(codcurso,cod);
}

void AlumnoNota::GetCodcurso(char *cod) const {
    if(codcurso==nullptr) cod[0]=0;
    else strcpy(cod,codcurso);
}

void AlumnoNota::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int AlumnoNota::GetCodigo() const {
    return codigo;
}

void operator >>(ifstream &arch,class AlumnoNota &alNota){
    int cod,ciclo,nota;
    char codCur[8],car;
    arch>>cod;
    if(arch.eof()) return;
    arch.get();
    arch.getline(codCur,8,',');
    arch>>ciclo>>car>>nota;
    alNota.SetNota(nota);
    alNota.SetCiclo(ciclo);
    alNota.SetCodcurso(codCur);
    alNota.SetCodigo(cod);
}

void AlumnoNota::operator &(class Nota &n){
    char codCurso[8];
    GetCodcurso(codCurso);
    n.SetCiclo(ciclo);
    n.SetCodcurso(codCurso);
    n.SetNota(nota);
}
