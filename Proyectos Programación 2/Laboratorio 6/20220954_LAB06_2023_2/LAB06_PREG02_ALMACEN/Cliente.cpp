/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: alulab14
 * 
 * Created on 22 de mayo de 2024, 11:16 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "Cliente.h"

Cliente::Cliente() {
    nombre=nullptr;
    dni=0;
    telefono=0;
    cantidad_productos_entregados=0;
    monto_total=0;
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
    if(nombre!=nullptr) delete nombre;
}

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

void Cliente::SetCantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
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

bool operator >> (ifstream &arch,class Cliente &cliente){
    int dni,telefono;
    char nombre[60];
    arch>>dni;
    if(arch.eof()) return false;
    arch.get();
    arch.getline(nombre,60,',');
    arch>>telefono;
    cliente.SetDni(dni);
    cliente.SetNombre(nombre);
    cliente.SetTelefono(telefono);
    return true;
}

void Cliente::operator +=(const class Pedido &ped){
    char codigo[8];
    double precio=ped.GetPrecio_producto();
    ped.GetCodigo(codigo);
    productos_entregados[cantidad_productos_entregados].SetCodigo(codigo);
    productos_entregados[cantidad_productos_entregados].SetPrecio(precio);
    cantidad_productos_entregados++;
    monto_total+=precio;
}

void operator <<(ofstream &arch,class Cliente &cli){
    char nombre[60];
    cli.GetNombre(nombre);
    arch<<cli.GetDni()<<setw(3)<<' '<<left<<setw(50)<<nombre<<right<<setw(10)<<
            cli.GetTelefono()<<setw(10)<<cli.GetMonto_total()<<setw(3)<<' '<<
            "Productos entregados: ";
    cli.imprimirPedidos(arch);
}

void Cliente::imprimirPedidos(ofstream &arch){
    char codigo[8];
    for(int i=0;i<cantidad_productos_entregados;i++){
        productos_entregados[i].GetCodigo(codigo);
        arch<<codigo<<' ';
    }
    arch<<endl;
}