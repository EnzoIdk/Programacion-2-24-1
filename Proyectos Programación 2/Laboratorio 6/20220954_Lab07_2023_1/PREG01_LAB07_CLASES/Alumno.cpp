/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: Enzo
 * 
 * Created on 23 de mayo de 2024, 04:25 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "Alumno.h"

Alumno::Alumno() {
    nombre=nullptr;
    numcursos=0;
    numaprobados=0;
    numprimera=0;
    numsegunda=0;
    numtercera=0;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
    if(nombre!=nullptr) delete nombre;
}

void Alumno::SetNumtercera(int numtercera) {
    this->numtercera = numtercera;
}

int Alumno::GetNumtercera() const {
    return numtercera;
}

void Alumno::SetNumsegunda(int numsegunda) {
    this->numsegunda = numsegunda;
}

int Alumno::GetNumsegunda() const {
    return numsegunda;
}

void Alumno::SetNumprimera(int numprimera) {
    this->numprimera = numprimera;
}

int Alumno::GetNumprimera() const {
    return numprimera;
}

void Alumno::SetNumaprobados(int numaprobados) {
    this->numaprobados = numaprobados;
}

int Alumno::GetNumaprobados() const {
    return numaprobados;
}

void Alumno::SetNumcursos(int numcursos) {
    this->numcursos = numcursos;
}

int Alumno::GetNumcursos() const {
    return numcursos;
}

void Alumno::SetNombre(const char *nomb) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Alumno::GetNombre(char *nomb) const {
    if(nombre==nullptr) nomb[0]=0;
    else strcpy(nomb,nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void operator >>(ifstream &arch,class Alumno &al){
    int cod;
    char nomb[60];
    arch>>cod;
    if(arch.eof()) return;
    arch.get();
    arch.getline(nomb,60,',');
    while(arch.get()!='\n');
    al.SetCodigo(cod);
    al.SetNombre(nomb);
}

void Alumno::operator +=(class Nota &nota){
    char codCurso[8];
    nota.GetCodcurso(codCurso);
    lnotas[numaprobados].SetCodigo(codigo);
    lnotas[numcursos].SetCiclo(nota.GetCiclo());
    lnotas[numcursos].SetCodcurso(codCurso);
    lnotas[numcursos].SetNota(nota.GetNota());
    numcursos++;
}

void operator <<(ofstream &arch,class Alumno &al){
    char nombre[60];
    al.GetNombre(nombre);
    arch<<"Codigo del Alumno: "<<al.GetCodigo()<<endl;
    arch<<"Nombre del Alumno: "<<nombre<<endl;
    arch<<"Detalle de Cursos: "<<endl;
    arch<<"Cursados Aprobados 1ra Vez 2da Vez 3ra Vez"<<endl;
    al.ImprimirCursos(arch);
}

void Alumno::ImprimirCursos(ofstream &arch){
    arch<<setw(3)<<' '<<numcursos<<setw(9)<<' '<<numaprobados<<setw(8)<<' '<<
            numprimera<<setw(7)<<' '<<numsegunda<<setw(7)<<' '<<numtercera<<endl;
//    arch<<lnotas[0].GetNota()<<endl;
}