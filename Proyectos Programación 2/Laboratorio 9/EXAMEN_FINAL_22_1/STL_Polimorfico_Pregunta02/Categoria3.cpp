/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Categoria3.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 12:51 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Categoria3.h"

Categoria3::Categoria3() {
    prioridad=0;
    descuento=0;
}

Categoria3::Categoria3(const Categoria3& orig) {
}

Categoria3::~Categoria3() {
}

void Categoria3::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Categoria3::GetDescuento() const {
    return descuento;
}

void Categoria3::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria3::GetPrioridad() const {
    return prioridad;
}

void Categoria3::leeProd(ifstream& arch){
    char car;
    arch>>prioridad>>car>>descuento;
    arch.get();
    Producto::leeProd(arch);
}

void Categoria3::imprimeProd(ofstream& arch){
    Producto::imprimeProd(arch);
    arch<<"Descuento: "<<descuento<<endl;
    arch<<"Prioridad: "<<prioridad<<endl<<endl;
}