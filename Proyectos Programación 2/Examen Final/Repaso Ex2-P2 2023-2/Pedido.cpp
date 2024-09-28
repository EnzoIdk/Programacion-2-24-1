/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Pedido.cpp
 * Author: Lucas
 * 
 * Created on 7 de julio de 2024, 01:50 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Pedido.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
Pedido::Pedido() {

}

Pedido::Pedido(const class Pedido &orig) {
    *this=orig;
}

Pedido::~Pedido() {

}

//GETTERS Y SETTERS
void Pedido::SetPeso(double peso) {
    this->peso = peso;
}

double Pedido::GetPeso() const {
    return peso;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string Pedido::GetCodigo() const {
    return codigo;
}

//METODOS
void Pedido::operator =(const class Pedido &orig){
    this->SetCodigo(orig.GetCodigo());
    this->SetCantidad(orig.GetCantidad());
    this->SetPeso(orig.GetPeso());
}

bool Pedido::operator <(const class Pedido &dato){
    return peso<dato.GetPeso();
}

void Pedido::leerDatos(ifstream &arch){
    string codTemp;
    int cantTemp;
    double pesoTemp;
    //LECTURA
    getline(arch, codTemp, ',');
    arch>>cantTemp;
    arch.get();
    arch>>pesoTemp;
    arch.get(); //\n
    //GUARDAMOS
    this->SetPeso(pesoTemp);
    this->SetCodigo(codTemp);
    this->SetCantidad(cantTemp);
}

void Pedido::mostrar(ofstream& arch){
    arch<<setw(10)<<this->GetCodigo()<<setw(10)<<this->GetPeso()<<
            this->GetCantidad()<<endl;
}

//FUNCIONES
