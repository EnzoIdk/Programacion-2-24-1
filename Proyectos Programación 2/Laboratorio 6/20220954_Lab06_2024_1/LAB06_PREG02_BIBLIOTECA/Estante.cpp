/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: Enzo
 * 
 * Created on 29 de mayo de 2024, 04:05 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Estante.h"
#define SIN_ESPACIO -1

Estante::Estante() {
    codigo=nullptr;
    espacios=nullptr;
    cantidad_libros=0;
}


Estante::~Estante() {
    if(codigo!=nullptr) delete codigo;
    if(espacios!=nullptr) delete espacios;
}

void Estante::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Estante::GetCantidad_libros() const {
    return cantidad_libros;
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

void operator >>(ifstream &arch,class Estante &est){
    char codigo[8];
    int altura,anchura;
    arch.getline(codigo,8,',');
    if(arch.eof()) return;
    arch>>altura;
    arch.get();
    arch>>anchura;
    arch.get();
    est.SetCodigo(codigo);
    est.SetAltura(altura);
    est.SetAnchura(anchura);
    est.InicializarEspacios();
}

// [0,1,2,3],[0,1,2,3] Anchura 2, Altura 4
void Estante::InicializarEspacios(){
    espacios=new class Espacio[altura*anchura];
    int n=0;
    for(int i=0;i<anchura;i++){
        for(int j=0;j<altura;j++){
            espacios[n].SetPosx(i);
            espacios[n].SetPosy(j);
            n++;
        }
    }
}

bool Estante::operator +=(class Libro& lib){
    int pos=EspacioDisponible(lib);
    if(pos!=SIN_ESPACIO and lib.GetAlto()<=altura){
        for(int i=pos;i<lib.GetAncho()+pos;i++){
            for(int j=0;j<lib.GetAlto();j++)
                espacios[i*altura+j].SetContenido('*');
        }
        lib.SetColocado(true);
        char nomb[60],cod[8];    
        libros[cantidad_libros].SetAlto(lib.GetAlto());
        libros[cantidad_libros].SetAncho(lib.GetAncho());
        lib.GetNombre(nomb);
        lib.GetCodigo(cod);
        libros[cantidad_libros].SetNombre(nomb);
        libros[cantidad_libros].SetCodigo(cod);
        libros[cantidad_libros].SetColocado(true);
        cantidad_libros++;
    }
    else{
        lib.SetColocado(false);
        return false;
    }
}

int Estante::EspacioDisponible(class Libro &lib){
    int num=0;
    for(int i=0;i<anchura;i++){
        if(espacios[i*altura].GetContenido()==' ') num++;
    }
    if(lib.GetAncho()<=num) return (anchura-num);
    else return SIN_ESPACIO;
}

void operator <<(ofstream &arch,class Estante &est){
    char codigo[8];
    est.GetCodigo(codigo);
    est.imprimirLinea(arch,60,'-');
    arch<<"Codigo Estante: "<<codigo<<setw(7)<<' '<<"Cantidad de Libros: "<<
            setw(2)<<est.GetCantidad_libros()<<endl<<"Anchura del Estante: "<<
            setw(2)<<est.GetAnchura()<<setw(3)<<' '<<"Altura del Estante: "<<
            setw(2)<<est.GetAltura()<<endl;
    est.imprimirLinea(arch,60,'-');
    for(int i=est.GetAltura()-1;i>=0;i--){
        for(int j=0;j<est.GetAnchura();j++){
            est.imprimirEspacio(arch,j,i);
        }
        arch<<endl;
    }
    arch<<endl<<"CODIGO"<<setw(3)<<' '<<"NOMBRE"<<setw(28)<<' '<<"ANCHO"<<' '<<"ALTO"<<endl;
    est.imprimirLinea(arch,60,'.');
    for(int i=0;i<est.GetCantidad_libros();i++) est.imprimirLibro(arch,i);
}

void Estante::imprimirLinea(ofstream &arch,int longitud,char simb){
    for(int i=0;i<longitud;i++) arch.put(simb);
    arch<<endl;
}

void Estante::imprimirEspacio(ofstream &arch,int posx,int posy){
    arch<<espacios[posx*altura+posy];
}

void Estante::imprimirLibro(ofstream &arch,int i){
    arch<<libros[i];
}