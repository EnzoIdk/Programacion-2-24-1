/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NProductos.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 12:44 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NProductos.h"
#include "Categoria1.h"
#include "Categoria2.h"
#include "Categoria3.h"

NProductos::NProductos() {
    prod=nullptr;
}

NProductos::NProductos(const NProductos& orig) {
    this->prod=orig.prod;
}

NProductos::~NProductos() {
//    if(prod!=nullptr) delete prod;
}

void NProductos::leeProductos(ifstream& arch){
    int cat;
    arch>>cat;
    if(arch.eof()) return;
    switch(cat){
        case 1:
            prod=new class Categoria1;
            break;
        case 2:
            prod=new class Categoria2;
            break;
        case 3:
            prod=new class Categoria3;
            break;
    }
    arch.get();
    prod->leeProd(arch);
}

void NProductos::imprimeProductos(ofstream& arch){
    prod->imprimeProd(arch);
}