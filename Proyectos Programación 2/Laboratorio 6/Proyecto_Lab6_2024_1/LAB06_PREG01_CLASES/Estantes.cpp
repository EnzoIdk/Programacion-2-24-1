/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estantes.cpp
 * Author: ISA
 * 
 * Created on 24 de mayo de 2024, 10:14 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Estantes.h"
#include "Libro.h"
#include "Espacio.h"

#define NO_ESPACIO -1
Estantes::Estantes() {
    altura = 0;
    anchura = 0;
    cantidad_libros = 0;
    codigo = nullptr;
    espacios = nullptr;
}

Estantes::Estantes(const Estantes& orig) {
}

Estantes::~Estantes() {
    if(codigo != nullptr) delete codigo;
    if(espacios != nullptr) delete espacios;
}

void Estantes::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Estantes::GetCantidad_libros() const {
    return cantidad_libros;
}

void Estantes::SetAltura(int altura) {
    this->altura = altura;
}

int Estantes::GetAltura() const {
    return altura;
}

void Estantes::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estantes::GetAnchura() const {
    return anchura;
}

void Estantes::SetCodigo(char *cad) {
    if (codigo != nullptr)delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo, cad);
}

void Estantes::GetCodigo(char *cad) const {
    if (codigo != nullptr)
        strcpy(cad, codigo);
}

bool Estantes::IsNotNullCodigo() const {
    bool IsNotNull = true;
    if (codigo == nullptr)IsNotNull = false;
    return IsNotNull;
}
void Estantes::SetMatriz(){
    if(altura != 0 and anchura != 0){
        espacios = new class Espacio[altura*anchura];
        LlenarCoordenadas();
    }else{
        cout << "Error en reserva de espacio en: " << codigo << endl;
        exit(1);
    }
}

void Estantes::LlenarCoordenadas(){
    int i = 0,k = 0,esp = 0;
    while(true){
        if(i < anchura){
            espacios[esp].SetPosx(i);
            espacios[esp].SetPosy(k);
            esp++;
            i++;
        }else if(k < altura - 1){
            i = 0;
            k++;
        }else break;
    }
}


ifstream & operator>>(ifstream &arch, class Estantes &Est){
    char codigo[8],c;
    int anchura,altura;
    arch.getline(codigo,8,',');
    if(not arch.eof()){
        arch >> anchura >> c >> altura;
        c = arch.get();
        Est.SetAnchura(anchura);
        Est.SetAltura(altura);
        Est.SetCodigo(codigo);
        Est.SetMatriz();
    }
    return arch;
}
void Estantes::ImprimirEspacio(ofstream &arch)const{
    if(espacios != nullptr){
        int i,k;
        for(i = (anchura-1)*altura-1;i >= 0;i-=anchura){
            for(k = -1;k < anchura-1;k++){
                arch << espacios[i+k];
            }
            arch << endl;
        }
    }else{
        arch << "No se reservo espacio en: " << codigo <<endl;
    }
    arch << endl;
}
void Estantes::GetLibroEn(int pos,class Libro &lib)const{
    char cadena[120];
    libros[pos].GetCodigo(cadena);
    lib.SetCodigo(cadena);
    libros[pos].GetNombre(cadena);
    lib.SetNombre(cadena);
    
    lib.SetColocado(libros[pos].IsColocado());
    lib.SetAlto(libros[pos].GetAlto());
    lib.SetAncho(libros[pos].GetAncho());
}
bool Estantes::operator+=(class Libro &lib){
    int pos = HayEspacio(lib);
    if(pos != NO_ESPACIO and lib.GetAlto() <= altura){
        int i = pos, k = 0, esp = pos;
        while(true) {
            if (i - pos < lib.GetAncho()) {
                espacios[esp].SetContenido('*');
                esp++;
                i++;
            } else if (k < lib.GetAlto()-1) {
                i = pos;
                esp += anchura - lib.GetAncho();
                k++;
            } else break;
        }
        lib.SetColocado(true);
        AnadirLibro(lib);
    }
    return pos != NO_ESPACIO and lib.GetAlto() <= altura;
}
int Estantes::HayEspacio(class Libro &lib){
    int i,num = 0;
    for(i = 0;i < anchura;i++)
        if(espacios[i].GetContenido() == ' ')num++;
    if(lib.GetAncho() <= num)return (anchura - num);
    return NO_ESPACIO;
}
void Estantes::AnadirLibro(class Libro &lib){
    libros[cantidad_libros].SetAlto(lib.GetAlto());
    libros[cantidad_libros].SetAncho(lib.GetAncho());
    libros[cantidad_libros].SetColocado(lib.IsColocado());
    char cadena[120];
    lib.GetCodigo(cadena);
    libros[cantidad_libros].SetCodigo(cadena);
    lib.GetNombre(cadena);
    libros[cantidad_libros].SetNombre(cadena);
    cantidad_libros++;
}
ofstream & operator<<(ofstream &arch, const class Estantes &Est){
    char codigo[12];
    Est.GetCodigo(codigo);
    arch << "Codigo Estante: " << codigo << setw(25) << "Cantidad de Libros: "
            << Est.GetCantidad_libros() << endl;
    arch << "Anclura del Estante: " << Est.GetAnchura() 
            << setw(25) << "Altura del Estante: "<< Est.GetAltura() << endl;
    arch << endl;
    Est.ImprimirEspacio(arch);
    arch << endl;
    class Libro lib;
    for(int i = 0;i < Est.GetCantidad_libros();i++){
        Est.GetLibroEn(i,lib);
        arch << lib;
    }
    arch << endl;
    return arch;
}