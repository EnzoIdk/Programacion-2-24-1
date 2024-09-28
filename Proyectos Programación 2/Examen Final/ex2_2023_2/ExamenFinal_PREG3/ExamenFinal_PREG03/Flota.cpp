/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flota.cpp
 * Author: margo
 * 
 * Created on 6 de julio de 2024, 19:32
 */

#include "Flota.h"
#include "Camion.h"
#include "Furgon.h"
#include <fstream>
#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

void Flota::cargar_vehiculos() {
    ifstream arch("vehiculos.csv", ios::in);
    if (not arch.is_open()){
        cout<<"error con la apertura del archivo "<<"vehiculos.csv"<<endl;
        exit(1);
    }
    char tipo;
    Vehiculo *ptr;
    int i=0;
    while(true){
        arch>>tipo;
        arch.get();
        switch(tipo){
            case 'F':
                ptr = new Furgon;
                break;
            case 'C':
                ptr = new Camion;
                break;
            default:
                ptr = nullptr;
                break;
        }
        i++;
        cout<<i<<endl;
        if(arch.eof()) break;
        ptr->lee(arch);
   vehiculos.insert({ptr->GetPlaca(),ptr});
        string cadena = ptr->GetPlaca();
        cout<<vehiculos[cadena]->GetPlaca()<<endl;
    }
}

void Flota::mostrar_vehiculos() {
    ofstream arch("mostrarVehiculos.txt", ios::out);
    if (not arch.is_open()){
        cout<<"error con la impresion "<<endl;
        exit(1);
    }
   
    arch<<"MOSTRAR VEHICULOS"<<endl;
    arch<<endl;
    for(const auto x:vehiculos){
        
       if (x.second!=nullptr){
           arch<<x.first<<endl;
           cout<<"se imprime second"<<endl;
           x.second->imprimir(arch);
       }else{
           cout<<"error no se encuentra sencod"<<endl;
       }
        arch<<endl;
    }
    vector<string>placas;
    placas.push_back("A1Q-612");
    placas.push_back("D9A-711");
    placas.push_back("O8J-848");
    placas.push_back("Q5J-871");
    placas.push_back("Z4L-514");
    mostrarReporte(arch,placas, 5);
}

void Flota::mostrarReporte(ofstream&arch,vector<string>&placas, int n) {
    arch<<"REPORTE DE AUTOS"<<endl;
    for(int i=0;i<n;i++){
        string placa=placas[i];
        if (vehiculos.count(placa)) 
            vehiculos[placa]->imprimir(arch);
        else arch<<"No se encontró al vehiculo"<<endl;
        arch<<endl;
    }
}

void Flota::cargar_pedidos(){
    ifstream arch("pedidos4.csv", ios::in);
    if(not arch.is_open()){
        cout<<"error con la lectura pedidos "<<endl;
        exit(1);
    }
    string codigo;
    Pedido pedido;
    int i=1;
    while(true){
        cout<<i<<endl;
        getline(arch,codigo ,',');
        if (arch.eof()) break;
        pedido.lee(arch);
      //  cout<<"codigo leido: "<<pedido.GetCodigo()<<endl;
//        cout<<vehiculos[codigo]->getPlaca()<<' ';
     if (vehiculos[codigo]!=nullptr) {
         vehiculos[codigo]->insertar(pedido);  
     }
        i++;
    } 
    cout<<"terminar pedidos"<<endl;
}