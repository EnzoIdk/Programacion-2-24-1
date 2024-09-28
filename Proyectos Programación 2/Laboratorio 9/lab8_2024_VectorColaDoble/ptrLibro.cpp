/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ptrLibro.cpp
 * Author: margo
 * 
 * Created on 20 de junio de 2024, 8:18
 */

#include "ptrLibro.h"
#include "Libro.h"
#include <fstream>
using namespace std;
ptrLibro::ptrLibro() {
    ptr=nullptr;
}

ptrLibro::ptrLibro(const ptrLibro& orig) {
}

ptrLibro::~ptrLibro() {
}

double ptrLibro::pesoLibro() {
    return ptr->GetPeso();
}


