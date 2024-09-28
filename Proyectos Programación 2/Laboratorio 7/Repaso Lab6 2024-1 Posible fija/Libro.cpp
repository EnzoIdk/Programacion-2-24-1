/* 
 * File:   Libro.cpp
 * Author: Lucas
 * 
 * Created on 30 de mayo de 2024, 19:28
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Libro.h"

//CONST Y DEST
Libro::Libro() {
    codigo=nullptr;
    nombre=nullptr;
    colocado=false;
    ancho=0;
    alto=0;
}

Libro::~Libro() {
    if(nombre!=nullptr) delete nombre;
    if(codigo!=nullptr) delete codigo;
}

//GETTERS Y SETTERS
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

void Libro::SetNombre(char * cad) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Libro::GetNombre(char * cad) const {
    if(nombre==nullptr) cad[0]=0;
    else strcpy(cad, nombre);
}

void Libro::SetCodigo(char * cad) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cad)+1];
    strcpy(codigo, cad);
}

void Libro::GetCodigo(char * cad) const {
    if(codigo==nullptr) cad[0]=0;
    else strcpy(cad, codigo);
}

//METODOS
void Libro::leer_datos(ifstream &arch){
    char cod[7], nombre[60];
    int anch, alt;
    //LEEMOS
    arch.getline(cod, 7, ',');
    arch.get(); //' '
    arch.getline(nombre, 60, ',');
    arch>>anch;
    arch.get(); //,
    arch>>alt;
    arch.get(); //,
    //GUARDAMOS
    SetNombre(nombre);
    SetCodigo(cod);
    SetAlto(alt);
    SetAncho(anch);
}

void Libro::imprimir(ofstream &arch){
    char cod[10], nombre[60];
    GetCodigo(cod);
    GetNombre(nombre);
    arch<<left<<setw(10)<<cod;
    if(colocado==true) arch<<setw(30)<<nombre;
    else arch<<"NO SE PUDO COLOCAR"<<setw(12)<<' ';
    arch<<right<<setw(10)<<ancho<<setw(10)<<alto<<endl;
}

//FUNCIONES
