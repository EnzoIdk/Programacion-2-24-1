/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: Enzo
 * 
 * Created on 13 de junio de 2024, 08:24 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>   
#include <cstring>
using namespace std;
#include "Estante.h"

Estante::Estante() {
    codigo=nullptr;
    pesoActual=0;
}

Estante::~Estante() {
    if(codigo!=nullptr) delete codigo;
}

void Estante::SetPesoActual(double pesoActual) {
    this->pesoActual = pesoActual;
}

double Estante::GetPesoActual() const {
    return pesoActual;
}

void Estante::SetPesoSoportado(double pesoSoportado) {
    this->pesoSoportado = pesoSoportado;
}

double Estante::GetPesoSoportado() const {
    return pesoSoportado;
}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(const char *cad) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cad)+1];
    strcpy(codigo,cad);
}

void Estante::GetCodigo(char *cad) const {
    if(codigo==nullptr) cad[0]=0;
    else strcpy(cad,codigo);
}

void Estante::leeEst(ifstream &arch){
    char cod[4],car;
    arch.getline(cod,4,',');
    SetCodigo(cod);
    arch>>anchura>>car>>altura>>car>>pesoSoportado;
    arch.get();
}

void Estante::imprimeEst(ofstream &arch){
    
}

void Estante::agregarLibro(class Libro *){
    
}