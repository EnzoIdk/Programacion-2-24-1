/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Categoria1.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 12:51 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Categoria1.h"

Categoria1::Categoria1() {
    prioridad=0;
    minimo=0;
}

Categoria1::Categoria1(const Categoria1& orig) {
}

Categoria1::~Categoria1() {
}

void Categoria1::SetMinimo(int minimo) {
    this->minimo = minimo;
}

int Categoria1::GetMinimo() const {
    return minimo;
}

void Categoria1::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria1::GetPrioridad() const {
    return prioridad;
}

void Categoria1::leeProd(ifstream& arch){
    char car;
    arch>>prioridad>>car>>minimo;
    arch.get();
    Producto::leeProd(arch);
}

void Categoria1::imprimeProd(ofstream& arch){
    Producto::imprimeProd(arch);
    arch<<"Stock Minimo: "<<minimo<<endl;
    arch<<"Prioridad: "<<prioridad<<endl<<endl;
}