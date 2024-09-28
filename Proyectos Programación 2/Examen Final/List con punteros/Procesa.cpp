/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Procesa.cpp
 * Author: Enzo
 * 
 * Created on 8 de julio de 2024, 07:08 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Procesa.h"
#include "Pedido.h"
#include "PedidoEspecial.h"
#include "PedidoEventual.h"
#include "PedidoUsual.h"

Procesa::Procesa() {
}

Procesa::Procesa(const Procesa& orig) {
}

Procesa::~Procesa() {
}

void Procesa::reserva(int cod, Pedido *&ped){
    if(cod<400000)
        ped=new PedidoEspecial;
    else if(cod>=400000 and cod<600000)
        ped=new PedidoUsual;
    if(cod>=600000)
        ped=new PedidoEventual;
}

void Procesa::carga(){
    Pedido *ped;
    int codigo;
    ifstream arch("pedidos5.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo pedidos5.csv"<<endl;
        exit(1);
    }
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        reserva(codigo,ped);
        ped->lee(codigo,arch);
        lped.push_back(ped);
    }
}

void Procesa::muestra(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    for(list<Pedido*>::iterator it=lped.begin();it!=lped.end();it++){
        (*it)->imprime(arch,0,0);
    }
}