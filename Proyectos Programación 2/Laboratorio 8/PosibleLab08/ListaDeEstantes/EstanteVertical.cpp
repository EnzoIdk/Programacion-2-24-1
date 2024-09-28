/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   EstanteVertical.cpp
 * Author: Enzo
 * 
 * Created on 13 de junio de 2024, 08:24 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>   
#include <cstring>
using namespace std;
#include "Estante.h"
#include "EstanteVertical.h"

EstanteVertical::EstanteVertical() {
    cantidad_enciclopedias=0;
}

void EstanteVertical::SetCantidad_enciclopedias(int cantidad_enciclopedias) {
    this->cantidad_enciclopedias = cantidad_enciclopedias;
}

int EstanteVertical::GetCantidad_enciclopedias() const {
    return cantidad_enciclopedias;
}

void EstanteVertical::leeEst(ifstream &arch){
    Estante::leeEst(arch);
}

void EstanteVertical::imprimeEst(ofstream &arch){
    Estante::imprimeEst(arch);
    char cod[10];
    GetCodigo(cod);
    arch<<"Codigo Estante: "<<cod<<setw(8)<<' '<<"Cantidad de libros: "<<cantidad_enciclopedias<<endl;
    arch<<"Anchura x Altura: "<<setw(2)<<GetAnchura()<<" x"<<setw(2)<<GetAltura()<<
            setw(3)<<' '<<"Peso Maximo: "<<setw(5)<<GetPesoSoportado()<<" Kg"<<endl;
    arch<<"Tipo: "<<left<<setw(21)<<"Vertical"<<right<<"Peso Total: "<<
            setw(6)<<GetPesoActual()<<" Kg"<<endl;
    arch<<"CODIGO"<<setw(2)<<' '<<"NOMBRE"<<setw(10)<<' '<<"ANCHO"<<
            setw(2)<<' '<<"ALTO"<<setw(2)<<' '<<"PESO"<<endl;
    for(int i=0;i<cantidad_enciclopedias;i++){
        enciclopedias[i].imprimirLib(arch);
    }
}

void EstanteVertical::agregarLibro(class Libro *lib){
    Estante::agregarLibro(lib);
    enciclopedias[cantidad_enciclopedias].SetAlto(lib->GetAlto());
    enciclopedias[cantidad_enciclopedias].SetAncho(lib->GetAncho());
    enciclopedias[cantidad_enciclopedias].SetColocado(true);
    lib->SetColocado(true);
    enciclopedias[cantidad_enciclopedias].SetPeso(lib->GetPeso());
    enciclopedias[cantidad_enciclopedias].SetVolumen(0);
    char aux1[20],aux2[60];
    lib->GetCodigo(aux1);
    lib->GetNombre(aux2);
    enciclopedias[cantidad_enciclopedias].SetCodigo(aux1);
    enciclopedias[cantidad_enciclopedias].SetNombre(aux2);
    cantidad_enciclopedias++;
}