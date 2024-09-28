/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Categoria2.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 12:51 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Categoria2.h"

Categoria2::Categoria2() {
    prioridad=0;
    descuento=0;
}

Categoria2::Categoria2(const Categoria2& orig) {
}

Categoria2::~Categoria2() {
}

void Categoria2::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Categoria2::GetDescuento() const {
    return descuento;
}

void Categoria2::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria2::GetPrioridad() const {
    return prioridad;
}

void Categoria2::leeProd(ifstream& arch){
    char car;
    arch>>prioridad>>car>>descuento;
    arch.get();
    Producto::leeProd(arch);
}

void Categoria2::imprimeProd(ofstream& arch){
    Producto::imprimeProd(arch);
    arch<<"Descuento: "<<descuento<<endl;
    arch<<"Prioridad: "<<prioridad<<endl<<endl; 
}