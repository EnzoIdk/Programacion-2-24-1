/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   EstanteHorizontal.cpp
 * Author: Enzo
 * 
 * Created on 13 de junio de 2024, 08:25 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>   
#include <cstring>
using namespace std;
#include "Estante.h"
#include "EstanteHorizontal.h"

EstanteHorizontal::EstanteHorizontal() {
    cantidad_novelas=0;
}

void EstanteHorizontal::SetCantidad_novelas(int cantidad_novelas) {
    this->cantidad_novelas = cantidad_novelas;
}

int EstanteHorizontal::GetCantidad_novelas() const {
    return cantidad_novelas;
}

void EstanteHorizontal::leeEst(ifstream &arch){
    Estante::leeEst(arch);
}

void EstanteHorizontal::imprimeEst(ofstream &arch){
    Estante::imprimeEst(arch);
    char cod[10];
    GetCodigo(cod);
    arch<<"Codigo Estante: "<<cod<<setw(8)<<' '<<"Cantidad de libros: "<<cantidad_novelas<<endl;
    arch<<"Anchura x Altura: "<<setw(2)<<GetAnchura()<<" x"<<setw(2)<<GetAltura()<<
            setw(3)<<' '<<"Peso Maximo: "<<setw(5)<<GetPesoSoportado()<<" Kg"<<endl;
    arch<<"Tipo: "<<left<<setw(21)<<"Horizontal"<<right<<"Peso Total: "<<
            setw(6)<<GetPesoActual()<<" Kg"<<endl;
    arch<<"CODIGO"<<setw(2)<<' '<<"NOMBRE"<<setw(10)<<' '<<"ANCHO"<<
            setw(2)<<' '<<"ALTO"<<setw(2)<<' '<<"PESO"<<endl;
    for(int i=0;i<cantidad_novelas;i++){
        novelas[i].imprimirLib(arch);
    }
}

void EstanteHorizontal::agregarLibro(class Libro *lib){
    Estante::agregarLibro(lib);
    novelas[cantidad_novelas].SetAlto(lib->GetAlto());
    novelas[cantidad_novelas].SetAncho(lib->GetAncho());
    novelas[cantidad_novelas].SetColocado(true);
    lib->SetColocado(true);
    double a=lib->GetPeso();
    novelas[cantidad_novelas].SetPeso(lib->GetPeso());
    char aux1[20],aux2[60],aux3[20];
    lib->GetCodigo(aux1);
    lib->GetNombre(aux2);
//    lib.GetTipo(aux3);
    novelas[cantidad_novelas].SetCodigo(aux1);
    novelas[cantidad_novelas].SetNombre(aux2);
    novelas[cantidad_novelas].SetTipo(" ");
    cantidad_novelas++;
}