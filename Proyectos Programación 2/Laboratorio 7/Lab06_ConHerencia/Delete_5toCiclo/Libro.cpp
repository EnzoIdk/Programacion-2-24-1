/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Enzo
 * 
 * Created on 30 de mayo de 2024, 10:31 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Libro.h"

Libro::Libro() {
    codigo=nullptr;
    nombre=nullptr;
    tipo=nullptr;
    colocado=false;
}

Libro::~Libro() {
    if(codigo!=nullptr) delete codigo;
    if(nombre!=nullptr) delete nombre;
    if(tipo!=nullptr) delete tipo;
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(const char *nomb) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Libro::GetNombre(char *nomb) const {
    if(nombre==nullptr) nomb[0]=0;
    else strcpy(nomb,nombre);
}

void Libro::SetCodigo(const char *cod) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cod)+1];
    strcpy(codigo,cod);
}

void Libro::GetCodigo(char *cod) const {
    if(codigo==nullptr) cod[0]=0;
    else strcpy(cod,codigo);
}

void Libro::SetTipo(const char *tip){
    if(tipo!=nullptr) delete tipo;
    tipo=new char[strlen(tip)+1];
    strcpy(tipo,tip);
}

void Libro::GetTipo(char *tip) const {
    if(tipo==nullptr) tip[0]=0;
    else strcpy(tip,tipo);
}

void Libro::leerDatos(ifstream &arch){
    char tip[20],cod[8],nomb[60];
    arch.getline(tip,20,',');
    if(arch.eof()) return;
    arch.get();
    arch.getline(cod,8,',');
    arch.get();
    arch.getline(nomb,60,',');
    SetTipo(tip);
    SetCodigo(cod);
    SetNombre(nomb);
    arch>>ancho;
    arch.get();
    arch>>alto;
    arch.get();
}

void Libro::imprime(ofstream &arch){
    arch<<codigo<<setw(3)<<' '<<left<<setw(40);
    if(colocado) arch<<nombre<<right;
    else arch<<"NO SE PUDO COLOCAR"<<right;
    arch<<setw(3)<<ancho<<setw(4)<<alto<<endl;
}