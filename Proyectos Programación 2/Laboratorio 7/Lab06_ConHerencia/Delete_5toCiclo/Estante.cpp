/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: Enzo
 * 
 * Created on 30 de mayo de 2024, 10:32 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Estante.h"

Estante::Estante() {
    codigo=nullptr;
    espacios=nullptr;
    cantidad_librosC=0;
    cantidad_librosF=0;
    cantidad_librosI=0;
}

Estante::~Estante() {
    if(codigo!=nullptr) delete codigo;
}

void Estante::SetCantidad_librosC(int cantidad_librosC) {
    this->cantidad_librosC = cantidad_librosC;
}

int Estante::GetCantidad_librosC() const {
    return cantidad_librosC;
}

void Estante::SetCantidad_librosI(int cantidad_librosI) {
    this->cantidad_librosI = cantidad_librosI;
}

int Estante::GetCantidad_librosI() const {
    return cantidad_librosI;
}

void Estante::SetCantidad_librosF(int cantidad_librosF) {
    this->cantidad_librosF = cantidad_librosF;
}

int Estante::GetCantidad_librosF() const {
    return cantidad_librosF;
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

void Estante::SetCodigo(const char *cod) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cod)+1];
    strcpy(codigo,cod);
}

void Estante::GetCodigo(char *cod) const {
    if(codigo==nullptr) cod[0]=0;
    else strcpy(cod,codigo);
}

void Estante::leerEstante(ifstream &arch){
    char cod[8];
    arch.getline(cod,8,',');
    if(arch.eof()) return;
    SetCodigo(cod);
    arch>>altura;
    arch.get();
    arch>>anchura;
    arch.get();
}

void Estante::inicializarEspacios(){
    int pos;
    if(espacios!=nullptr) delete[] espacios;
    espacios=new class Espacio[altura*anchura+1];
    for(int i=0;i<anchura;i++){
        for(int j=0;j<altura;j++){
            pos=i*altura+j;
            espacios[pos].SetPosx(i);
            espacios[pos].SetPosy(j);
        }
    }
}

void Estante::asignarLibro(class Fisica &libro){
    char cod[8],nomb[60],cad[20];
    int ancho=libro.GetAncho(),alto=libro.GetAlto(),pos=espacioDisp();
    if(pos!=-1 and alto<=altura and ancho<=anchura-pos){
        for(int i=pos;i<ancho+pos;i++){
            for(int j=0;j<alto;j++){
                espacios[i*altura+j].SetContenido('*');
            }
        }
        libro.GetCodigo(cod);
        libro.GetNombre(nomb);
        libro.GetProfesor(cad);
        librosF[cantidad_librosF].SetAlto(alto);
        librosF[cantidad_librosF].SetAncho(ancho);
        librosF[cantidad_librosF].SetCodigo(cod);
        librosF[cantidad_librosF].SetNombre(nomb);
        librosF[cantidad_librosF].SetProfesor(cad);
        librosF[cantidad_librosF].SetColocado(true);
        libro.SetColocado(true);
        cantidad_librosF++;
    }
}

void Estante::asignarLibro(class Informatica &libro){
    
}

void Estante::asignarLibro(class Calculo &libro){
    
}

int Estante::espacioDisp(){
    for(int i=0;i<anchura;i++){
        if(espacios[i*altura].GetContenido()==' ') return i;
    }
    return -1;
}

void Estante::imprime(ofstream &arch){
    for(int i=1;i<=altura;i++){
        for(int j=1;j<=anchura;j++){
            espacios[j*altura-i].imprime(arch);
        }
        arch<<endl;
    }
}