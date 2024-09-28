/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.cpp
 * Author: margo
 * 
 * Created on 29 de mayo de 2024, 9:13
 */

#include "Biblioteca.h"
#include "Espacio.h"
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
Biblioteca::Biblioteca() {
    lit=nullptr;
    mat=nullptr;
    estantesLit=0;
    estantesMat=0;
    totalLibros=0;

}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
    if (lit!=nullptr) delete lit;
    if (mat!=nullptr) delete mat;
}

void Biblioteca::SetTotalLibros(int totalLibros) {
    this->totalLibros = totalLibros;
}

int Biblioteca::GetTotalLibros() const {
    return totalLibros;
}

void Biblioteca::SetEstantesLit(int estantesLit) {
    this->estantesLit = estantesLit;
}

int Biblioteca::GetEstantesLit() const {
    return estantesLit;
}

void Biblioteca::SetEstantesMat(int estantesMat) {
    this->estantesMat = estantesMat;
}

int Biblioteca::GetEstantesMat() const {
    return estantesMat;
}

void Biblioteca::cargarLibros() {
    ifstream arch("libros.csv", ios::in);
    if (not arch.is_open()){
        cout<<"error con la apertura de los archivos:"<<endl;
        exit(1);
    }
    //MAT M001, Cálculo Integral, 3, 5, DESC12
    char cod[3]{};
    int i=0, j=0;
    while(true){
        arch>>cod;
        if (arch.eof()) break;
        if (strcmp(cod, "MAT")==0){
            lmat[i].lectura(arch);
            i++;
        }else{
            llit[j].lectura(arch);
            j++;
        }
    }
}

void Biblioteca::cargarEstantes() {
    //L CCC, 5, 3
     ifstream arch("estantes.csv", ios::in);
    if (not arch.is_open()){
        cout<<"error con la apertura de los archivos:"<<endl;
        exit(1);
    }
     int n=0, n2=0;
     mat = new Estante [20]{};
     lit = new Estante [20]{};
     char cod;
     while(true){
         arch>>cod;
         if (arch.eof()) break;
         if (cod!='M'){//lite
             lit[n].llenarEstante(arch);
             n++;
         }else{
             mat[n2].llenarEstante(arch);
             n2++;
         }
     }
     SetEstantesLit(n);
     SetEstantesMat(n2);
}

void Biblioteca::agregarLibros() {
    agregarMatematica();
    agregarLiteratura();
}

void Biblioteca::agregarMatematica() {
    int k=0,i;
    for( i=0;i<estantesMat;i++){
        cout<<"estante"<<i+1<<endl;
        for(;lmat[k].GetAncho()!=0;k++){
            if (!mat[i].agregarLibro(lmat[k])) break;
        }
    }
}

void Biblioteca::agregarLiteratura() {
      int k=0,i;
    for( i=0;i<estantesLit;i++){
        for(;llit[k].GetAncho()!=0;k++){
            if (!lit[i].agregarLibro(llit[k])) break;
        }
    }
}

void Biblioteca::impresion() {
    ofstream arch("impresion.txt", ios::out);
    if (not arch.is_open()){
        cout<<"error con la apertura del archivo"<<endl;
        exit(1);
    }
    arch<<"Estante Matematica"<<endl;
    impresionEstanteMatematica(arch);
    
    arch<<"Estante Litearatura"<<endl;
    impresionEstanteLiteratura(arch);
}

void Biblioteca::impresionEstanteMatematica(ofstream&arch) {
    for(int i=0;i<estantesMat;i++){
        mat[i].impresionEstante(arch);
    }
}
void Biblioteca::impresionEstanteLiteratura(ofstream&arch) {
    for(int i=0;i<estantesLit;i++){
        lit[i].impresionEstante(arch);
    }
}
