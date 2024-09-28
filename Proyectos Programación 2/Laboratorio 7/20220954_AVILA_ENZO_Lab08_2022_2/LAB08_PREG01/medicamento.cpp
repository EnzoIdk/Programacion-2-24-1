/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medicamento.cpp
 * Author: aml
 * 
 * Created on 29 de mayo de 2024, 08:54 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "medicamento.h"

medicamento::medicamento() {
    nombre=nullptr;
    codigo=0;
}

medicamento::~medicamento() {
    if(nombre==nullptr) delete nombre;
}

void medicamento::SetFecha(int fecha) {
    this->fecha = fecha;
}

int medicamento::GetFecha() const {
    return fecha;
}

void medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double medicamento::GetPrecio() const {
    return precio;
}

void medicamento::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int medicamento::GetCantidad() const {
    return cantidad;
}

void medicamento::SetNombre(const char *nomb) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void medicamento::GetNombre(char *nomb) const {
    if(nombre==nullptr) nomb[0]=0;
    else strcpy(nomb,nombre);
}

void medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medicamento::GetCodigo() const {
    return codigo;
}

void medicamento::asignarDatos(int codMedicamento,int cantidad,int fecha){
    ifstream arch("Medicamentos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Medicamentos.csv"<<endl;
        exit(1);
    }
    SetCantidad(cantidad);
    SetFecha(fecha);
    int cod;
    char nomb[60];
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        if(cod==codMedicamento){
            SetCodigo(cod);
            arch.get();
            arch.getline(nomb,60,',');
            SetNombre(nomb);
            arch>>precio;
        }
        else while(arch.get()!='\n');
    }
}

void medicamento::imprimir(ofstream &arch){
    char descripcion[60];
    GetNombre(descripcion);
    arch<<GetCodigo()<<setw(3)<<' '<<left<<setw(60)<<descripcion<<right<<
            setw(4)<<GetCantidad()<<setw(5)<<' ';
}