/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Nota.cpp
 * Author: Enzo
 * 
 * Created on 25 de junio de 2024, 12:46 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Nota.h"

Nota::Nota() {
    codigo_curso=nullptr;
    ciclo=0;
    vez=0;
}

Nota::Nota(const Nota& orig) {
    char cad[60];
    codigo_curso=nullptr;
    SetCiclo(orig.GetCiclo());
    orig.GetCodigo_curso(cad);
    SetCodigo_curso(cad);
    SetCreditos(orig.GetCreditos());
    SetCalificacion(orig.GetCalificacion());
    SetVez(orig.GetVez());
}

Nota::~Nota() {
    if(codigo_curso!=nullptr) delete codigo_curso;
}

void Nota::SetVez(int vez) {
    this->vez = vez;
}

int Nota::GetVez() const {
    return vez;
}

void Nota::SetCalificacion(int calificacion) {
    this->calificacion = calificacion;
}

int Nota::GetCalificacion() const {
    return calificacion;
}

void Nota::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Nota::GetCreditos() const {
    return creditos;
}

void Nota::SetCodigo_curso(const char *cad) {
    if(codigo_curso!=nullptr) delete codigo_curso;
    codigo_curso=new char[strlen(cad)+1];
    strcpy(codigo_curso,cad);
}

void Nota::GetCodigo_curso(char *cad) const {
    if(codigo_curso==nullptr) cad[0]=0;
    else strcpy(cad,codigo_curso);
}

void Nota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Nota::GetCiclo() const {
    return ciclo;
}

void operator >>(ifstream &arch,class Nota &nota){
    char cod[10];
    double cred;
    int calif;
    arch.getline(cod,10,',');
    arch>>cred;
    arch.get();
    arch>>calif;
    nota.SetCodigo_curso(cod);
    nota.SetCreditos(cred);
    nota.SetCalificacion(calif);
    //la ',' o el '\n' será leído en una iteración futura supongo
}

void Nota::imprimeNota(ofstream& arch){
    arch<<left<<setw(10)<<codigo_curso<<right<<ciclo<<setw(6)<<' '<<setfill('0')<<
            setw(2)<<calificacion<<setfill(' ')<<setw(5)<<vez<<setw(12)<<
            creditos<<endl;
}

void Nota::asignarCiclo(int ciclo){
    SetCiclo(ciclo);
}