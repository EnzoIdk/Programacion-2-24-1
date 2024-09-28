/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.cpp
 * Author: margo
 * 
 * Created on 8 de julio de 2024, 18:37
 */

#include "Nota.h"
#include "Alumno.h"
#include <cstring>
#include <fstream>
using namespace std;
Nota::Nota() {
    codigo_curso=nullptr;
    ciclo=0;
    calificacion=0;
    creditos=0;
    vez=0;
    
}

Nota::Nota(const Nota& notta) {
   codigo_curso=nullptr;
   calificacion=notta.calificacion;
    ciclo=notta.ciclo;
    creditos=notta.creditos;
    vez=notta.vez;
    char cod[10]{};
    notta.GetCodigo_curso(cod);
    SetCodigo_curso(cod);
}

Nota::~Nota() {
    if (codigo_curso!=nullptr) delete codigo_curso;
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

void Nota::SetCodigo_curso(char* cod) {
    if (codigo_curso!=nullptr) delete codigo_curso;
    codigo_curso=new char[strlen(cod)+1]{};
    strcpy(codigo_curso, cod);
}

void Nota::GetCodigo_curso(char *cod) const {
    if (codigo_curso!=nullptr) strcpy(cod, codigo_curso);
    else cod[0]=0;
}

void Nota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Nota::GetCiclo() const {
    return ciclo;
}

void operator >>(ifstream &arch, Nota&nota){
    char codigo[10]{};
    double cre;
    int notai;
    arch.getline(codigo, 10, ',');
//    cout<<codigo<<endl;
    arch>>cre;
    arch.get();
    arch>>notai;
    nota.SetCalificacion(notai);
    nota.SetCodigo_curso(codigo);
    nota.SetCreditos(cre);
}
void operator <<(ofstream&arch, Nota&nota){
    arch<<"    Calificacion:    "<<nota.GetCalificacion()<<endl;
    arch<<"    Ciclo:           "<<nota.GetCiclo()<<endl;
    char codigo[10]{};
    nota.GetCodigo_curso(codigo);
    arch<<"    Codigo:          "<<codigo<<endl;
    arch<<"    Creditos:        "<<nota.GetCreditos()<<endl;
}

void Nota::operator=(Nota&notta) {
    calificacion=notta.calificacion;
    ciclo=notta.ciclo;
    creditos=notta.creditos;
    vez=notta.vez;
    char cod[10]{};
    notta.GetCodigo_curso(cod);
    SetCodigo_curso(cod);
}
