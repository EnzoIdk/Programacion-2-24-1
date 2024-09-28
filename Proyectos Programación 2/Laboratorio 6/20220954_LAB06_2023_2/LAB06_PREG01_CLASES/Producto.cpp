/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: aml
 * 
 * Created on 22 de mayo de 2024, 12:55 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "Producto.h"

Producto::Producto() {
    cantidad_clientes_no_servidos=0;
    cantidad_clientes_servidos=0;
    stock=0;
    precio=0;
    descripcion=nullptr;
    codigo=nullptr;
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
    if(descripcion!=nullptr) delete descripcion;
    if(codigo!=nullptr) delete codigo;
}

void Producto::SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

void Producto::SetCantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetDescripcion(const char *desc) {
    if(descripcion!=nullptr) delete descripcion;
    descripcion=new char[strlen(desc)+1];
    strcpy(descripcion,desc);
}

void Producto::GetDescripcion(char *desc) const {
    if(descripcion==nullptr) desc[0]=0;
    else strcpy(desc,descripcion);
}

void Producto::SetCodigo(const char *cod) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cod)+1];
    strcpy(codigo,cod);
}

void Producto::GetCodigo(char *cod) const {
    if(codigo==nullptr) cod[0]=0;
    else strcpy(cod,codigo);
}

bool operator >> (ifstream &arch,class Producto &prod){
    char codigo[8],descripcion[60];
    double precio;
    int stock;
    arch.getline(codigo,8,',');
    if(arch.eof()) return false;
    arch.getline(descripcion,60,',');
    arch>>precio;
    arch.get();
    arch>>stock;
    arch.get();
    prod.SetCodigo(codigo);
    prod.SetDescripcion(descripcion);
    prod.SetPrecio(precio);
    prod.SetStock(stock);
    return true;
}

/*agrega un pedido a un producto*/

bool Producto::operator +=(const class Pedido &ped){
    if(stock>0){
        clientes_servidos[cantidad_clientes_servidos]=ped.GetDni_cliente();
        cantidad_clientes_servidos++;
        stock--;
        return true;
    }
    else{
        clientes_no_servidos[cantidad_clientes_no_servidos]=ped.GetDni_cliente();
        cantidad_clientes_no_servidos++;
        return false;
    }
}

void operator <<(ofstream &arch,class Producto &prod){
    char codigo[8],desc[60];
    prod.GetCodigo(codigo);
    prod.GetDescripcion(desc);
    arch<<setprecision(2)<<fixed;
    arch<<codigo<<setw(3)<<' '<<left<<setw(60)<<desc<<right<<setw(10)<<
            prod.GetPrecio()<<setw(5)<<prod.GetStock()<<endl;
    prod.ImprimirClientes(arch);
}

void Producto::ImprimirClientes(ofstream &arch){
    arch<<"Clientes atendidos: ";
    if(cantidad_clientes_servidos==0) arch<<"NO SE ATENDIERON PEDIDOS"<<endl;
    else{
        for(int i=0;i<cantidad_clientes_servidos;i++) arch<<clientes_servidos[i]<<' ';
        arch<<endl;
        arch<<"Clientes no atendidos: ";
        if(cantidad_clientes_no_servidos==0) arch<<"NO HAY CLIENTES SIN ATENDER"<<endl;
        else{
            for(int i=0;i<cantidad_clientes_no_servidos;i++) arch<<clientes_no_servidos[i]<<' ';
            arch<<endl;
        }
    }
}
