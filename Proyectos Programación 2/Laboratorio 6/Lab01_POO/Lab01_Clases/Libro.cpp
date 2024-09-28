/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Enzo
 * 
 * Created on 23 de mayo de 2024, 09:00 PM
 */

#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Libro.h"

using namespace std;

Libro::Libro() {
    autor=nullptr;
    titulo=nullptr;
    codigo=nullptr;
    precio=0;
    stock=0;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
    if(autor!=nullptr) delete autor;
    if(titulo!=nullptr) delete titulo;
    if(codigo!=nullptr) delete codigo;
}

void Libro::SetPrecio(double precio) {
    this->precio = precio;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetStock(int stock) {
    this->stock = stock;
}

int Libro::GetStock() const {
    return stock;
}

void Libro::SetAutor(const char *aut) {
    if(autor!=nullptr) delete autor;
    autor=new char[strlen(aut)+1];
    strcpy(autor,aut);
}

void Libro::GetAutor(char *aut) const {
    if(autor==nullptr) aut[0]=0;
    else strcpy(aut,autor);
}

void Libro::SetTitulo(const char *tit) {
    if(titulo!=nullptr) delete titulo;
    titulo=new char[strlen(tit)+1];
    strcpy(titulo,tit);
}

void Libro::GetTitulo(char *tit) const {
    if(titulo==nullptr) tit[0]=0;
    else strcpy(tit,titulo);
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

bool operator >>(ifstream &arch,class Libro &lib){
    char codigo[8],titulo[60],autor[60];
    int stock;
    double precio;
    arch.getline(codigo,8,',');
    if(arch.eof()){
        lib.SetCodigo("FIN");
        return false;
    }
    arch.getline(titulo,60,',');
    arch.getline(autor,60,',');
    arch>>stock;
    arch.get();
    arch>>precio;
    arch.get();
    lib.SetAutor(autor);
    lib.SetCodigo(codigo);
    lib.SetTitulo(titulo);
    lib.SetStock(stock);
    lib.SetPrecio(precio);
    return true;
}

void operator <<(ofstream &arch,class Libro &lib){
    char codigo[8],titulo[60],autor[60];
    lib.GetCodigo(codigo);
    lib.GetAutor(autor);
    lib.GetTitulo(titulo);
    arch<<setprecision(2)<<fixed;
    arch<<left<<setw(10)<<codigo<<setw(60)<<titulo<<setw(40)<<autor<<right<<
            setw(5)<<lib.GetStock()<<setw(10)<<lib.GetPrecio()<<endl;
}