/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: margo
 * 
 * Created on 8 de julio de 2024, 18:48
 */

#include "Nodo.h"

Nodo::Nodo() {
    anterior=nullptr;
    siguiente=nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

//Nodo::~Nodo() {
//}
//
//int Nodo::obtenerCodigo() {
//    return dato.codigoAlumno();
//}

void Nodo::agregarAlumno(Alumno&al) {
    dato.agregarAlumno(al);
}

int Nodo::codiogAlumno() {
    return dato.codigoAlumno();
}

void Nodo::imprime(ofstream&arch) {
    dato.impresion(arch);
}

void Nodo::agregarNotas(vector<Nota>& notas) {
    dato.agregarNotas(notas);
}
