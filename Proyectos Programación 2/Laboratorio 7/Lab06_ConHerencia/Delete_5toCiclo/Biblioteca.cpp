/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Enzo
 * 
 * Created on 30 de mayo de 2024, 10:32 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "Biblioteca.h"

Biblioteca::Biblioteca() {
    cant_LibrosC=0;
    cant_LibrosF=0;
    cant_LibrosI=0;
    cantidad_estantes=0;
}

void Biblioteca::SetCant_LibrosC(int cant_LibrosC) {
    this->cant_LibrosC = cant_LibrosC;
}

int Biblioteca::GetCant_LibrosC() const {
    return cant_LibrosC;
}

void Biblioteca::SetCant_LibrosI(int cant_LibrosI) {
    this->cant_LibrosI = cant_LibrosI;
}

int Biblioteca::GetCant_LibrosI() const {
    return cant_LibrosI;
}

void Biblioteca::SetCant_LibrosF(int cant_LibrosF) {
    this->cant_LibrosF = cant_LibrosF;
}

int Biblioteca::GetCant_LibrosF() const {
    return cant_LibrosF;
}

void Biblioteca::SetCantidad_estantes(int cantidad_estantes) {
    this->cantidad_estantes = cantidad_estantes;
}

int Biblioteca::GetCantidad_estantes() const {
    return cantidad_estantes;
}

