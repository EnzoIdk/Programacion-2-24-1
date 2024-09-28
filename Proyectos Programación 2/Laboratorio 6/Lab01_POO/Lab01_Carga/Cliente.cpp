/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: Enzo
 * 
 * Created on 23 de mayo de 2024, 09:00 PM
 */

#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Cliente.h"
#include "LibroPedido.h"

using namespace std;


Cliente::Cliente() {
    nombre=nullptr;
    dni=0;
    montoTotal=0;
    cantLibros=0;
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
    if(nombre!=nullptr) delete nombre;
}

void Cliente::SetMontoTotal(double montoTotal) {
    this->montoTotal = montoTotal;
}

double Cliente::GetMontoTotal() const {
    return montoTotal;
}

void Cliente::SetCantLibros(int cantLibros) {
    this->cantLibros = cantLibros;
}

int Cliente::GetCantLibros() const {
    return cantLibros;
}

void Cliente::SetNombre(const char *nomb) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Cliente::GetNombre(char *nomb) const {
    if(nombre==nullptr) nomb[0]=0;
    else strcpy(nomb,nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

bool operator >>(ifstream &arch,class Cliente &cli){
    int dni;
    char nombre[60];
    arch>>dni;
    if(arch.eof()) return false;
    arch.get();
    arch.getline(nombre,60,'\n');
    cli.SetDni(dni);
    cli.SetNombre(nombre);
    return true;
}

bool Cliente::operator <<(class LibroPedido &ped){
    char codigo[8];
    if(cantLibros<30){
        librosSolicitados[cantLibros].SetNumPedido(ped.GetNumPedido());
        librosSolicitados[cantLibros].SetPrecio(ped.GetPrecio());
        librosSolicitados[cantLibros].SetAtendido(ped.IsAtendido());
        ped.GetCodLibro(codigo);
        librosSolicitados[cantLibros].SetCodLibro(codigo);
        cantLibros++;
        return true;
    }
    else return false;
}

void Cliente::operator ++(void){
    for(int i=0;i<cantLibros;i++){
        if(librosSolicitados[i].IsAtendido()) 
            montoTotal+=librosSolicitados[i].GetPrecio();
    }
}

void operator <<(ofstream &arch,class Cliente &cli){
    char nombre[60];
    cli.GetNombre(nombre);
    arch<<cli.GetDni()<<setw(3)<<' '<<nombre<<endl;
    arch<<setprecision(2)<<fixed;
    cli.ImprimirPedidos(arch);
}

void Cliente::ImprimirPedidos(ofstream &arch){
    char codigo[8];
    arch<<"Libros entregados:"<<endl;
    arch<<setw(4)<<' '<<"Pedido No."<<setw(4)<<' '<<"Codigo"<<setw(5)<<' '<<"Precio"<<endl;
    for(int i=0;i<cantLibros;i++){
        if(librosSolicitados[i].IsAtendido()){
            librosSolicitados[i].GetCodLibro(codigo);
            arch<<setw(7)<<' '<<setfill('0')<<setw(5)<<librosSolicitados[i].GetNumPedido()<<
                    setfill(' ')<<setw(6)<<' '<<codigo<<setw(10)<<librosSolicitados[i].GetPrecio()<<endl;
        }
    }
    arch<<"Total a pagar: "<<montoTotal<<endl;
    arch<<"Libros no entregados por falta de stock: "<<endl;
    arch<<setw(4)<<' '<<"Pedido No."<<setw(4)<<' '<<"Codigo"<<endl;
    for(int i=0;i<cantLibros;i++){
        if(!librosSolicitados[i].IsAtendido()){
            librosSolicitados[i].GetCodLibro(codigo);
            arch<<setw(7)<<' '<<setfill('0')<<setw(5)<<librosSolicitados[i].GetNumPedido()<<
                    setfill(' ')<<setw(6)<<' '<<codigo<<endl;
        }
    }
}