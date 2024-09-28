/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.cpp
 * Author: margo
 * 
 * Created on 29 de mayo de 2024, 9:13
 */

#include "Estante.h"
#include "Libro.h"
#include <cstring>
#include <iostream>
using namespace std;
Estante::Estante() {
    codigo=nullptr;
    libros=nullptr;
    espacios=nullptr;
    altura=0;
    anchura=0;
    cant_libros=0;
}

Estante::Estante(const Estante& orig) {
}

Estante::~Estante() {
    if (codigo!=nullptr) delete codigo;
    if (libros!=nullptr) delete libros;
    if (espacios!=nullptr) delete espacios;
}

void Estante::SetCant_libros(int cant_libros) {
    this->cant_libros = cant_libros;
}

int Estante::GetCant_libros() const {
    return cant_libros;
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

void Estante::SetCodigo(const char* cod) {
    if (codigo!=nullptr) delete codigo;
    codigo=new char [strlen(cod)+1]{};
    strcpy(codigo, cod);
}

void Estante::GetCodigo(char *cod) const {
    if (codigo==nullptr){
        cod[0]=0;
    }else{
        strcpy(cod, codigo);
    }
}
//L CCC, 5, 3

void Estante::llenarEstante(ifstream &arch) {
    char cod[5]{};
    int alt, anch;
    arch.getline(cod, 10, ',');
    arch>>alt;
    arch.get();
    arch>>anch;
    
    SetAltura(alt);
    SetAnchura(anch);
    SetCodigo(cod);
}
int cantLibros=0;
bool Estante::agregarLibro(Libro&lib) {
    int anch=lib.GetAncho();
    int alt=lib.GetAlto();
    int pos;
    if (cant_libros==0) {
        libros=new Libro [20]{};
        espacios=new Espacio [max()]{};
    }
    cantLibros++;
    cout<<cantLibros<<endl;
    
    if (hayEspacio(pos, anch, alt)){
        pintarEspacio(anch, alt, pos);
        libros[cant_libros].agregarDatosLibro(lib);
        cant_libros++;
        return true;
    }
    
    return false;
}

void Estante::pintarEspacio(int anc, int alt, int pos) {
    int cont=0;
    int cont2=0;
    
    for(int i=pos;i<max() and cont<anc;i++){
        for (int k=i;k>=0 and cont2<alt;k-=anchura){
            espacios[k].SetContenido('*');
            cout<<espacios[k].GetContenido()<<' ';
            cont2++;
        }
        cout<<endl;
        cont2=0;
        cont++;
    }
    
}
int Estante::max() {
    return altura*anchura;
}
bool Estante::hayEspacio(int&pos, int anc, int alt) {
    int cont=anc;
    int con2=alt;
    pos=max()-anchura;//inicio del arreglo
    if (alt>altura or anc>anchura) return false;
    for(int i=pos;i<altura*anchura;i++){
        if (espacios[i].GetContenido()==' '){
            cont--;
        }else{
            pos++;
        }
        if (cont==0) return true;
    }
    return false;
}

void Estante::impresionEstante(ofstream&arch) {
    int cont=1;
    for(int i=0;i<altura*anchura;i++){
        if (espacios!=nullptr)arch<<'['<<espacios[i].GetContenido()<<']'<<' ';
        if (cont==anchura){
            arch<<endl;
            cont=0;
        }
        cont++;
    }
    arch<<endl;
}
