/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.cpp
 * Author: Jeremy Lopez Galindo
 * 
 * Created on 4 de diciembre de 2023, 06:41 PM
 */

#include "Nota.h"

Nota::Nota() {
    calificacion = 0;
    ciclo = 0;
    codigo_curso = nullptr;
    creditos = 0;vez = 0;
}

Nota::Nota(const Nota& orig) {
    codigo_curso = nullptr;
    *this = orig;
}

Nota::~Nota() {
    if(codigo_curso)delete codigo_curso;
}

int Nota::getCalificacion() const {
    return calificacion;
}

int Nota::getCiclo() const {
    return ciclo;
}

void Nota::getCodigoCurso(char* cad)const {
    if(codigo_curso == nullptr)cad[0] = 0;
    else strcpy(cad,codigo_curso);
}

double Nota::getCreditos() const {
    return creditos;
}

int Nota::getVez() const {
    return vez;
}

void Nota::setCalificacion(int c) {
    calificacion = c;
}

void Nota::setCiclo(int c) {
    ciclo = c;
}

void Nota::setCodigoCurso(char* cad) {
    if(codigo_curso)delete codigo_curso;
    codigo_curso = new char[strlen(cad)+1];
    strcpy(codigo_curso,cad);
}

void Nota::setCreditos(double c) {
    creditos = c;
}

void Nota::setVez(int v) {
    vez = v;
}

void Nota::operator=(const Nota& otro) {
    char cod[200];
    otro.getCodigoCurso(cod);
    setCalificacion(otro.getCalificacion());
    setCiclo(otro.getCiclo());
    setCreditos(otro.getCreditos());
    setVez(otro.getVez());
    setCodigoCurso(cod);
}

void operator>>(ifstream &in,Nota &nota){
    char cod[20];
    double cred;
    int cal;
    in.getline(cod,20,',');
    if(in.eof())return;
    in>>cred;
    in.get();
    in>>cal;
    nota.setCalificacion(cal);
    nota.setCodigoCurso(cod);
    nota.setCreditos(cred);
}

void Nota::imprimeNota(ofstream& out) {
    char cod[20];
    getCodigoCurso(cod);
    out<<setw(10)<<getCiclo()<<setw(10)<<cod<<setw(10)<<getCreditos()<<setw(15)<<getCalificacion()<<setw(10)<<getVez()<<endl;
}
