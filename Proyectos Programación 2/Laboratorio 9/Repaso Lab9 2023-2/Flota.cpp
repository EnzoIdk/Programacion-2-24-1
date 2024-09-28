/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Flota.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 12:27
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
#include <cstring>

#include "Flota.h"

#define MAXLINEA 80
#define NOTFOUND -1

//CONSTRUCTOR, COPIA, DESTRUCTOR
Flota::Flota() {
    
}

Flota::Flota(const class Flota &orig) {

}

Flota::~Flota() {
    //ACA DESTRUIMOS
    for(auto vehiculo:vflota){
        vehiculo.eliminar();
    }
}

//GETTERS Y SETTERS

//METODOS
void Flota::cargaFlota(const char* nomb){
    ifstream arch(nomb, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    class NVehiculo temp;
    //C,20864087,O5L-856,1000,2,6
    while(true){
        temp.lee(arch);
        if(arch.eof()) break;
        vflota.push_back(temp);
    }
    vflota.shrink_to_fit();
    sort(vflota.begin(), vflota.end());
}

void Flota::muestraCarga(const char* nomb){
    ofstream arch(nomb, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    arch<<fixed<<setprecision(2);
    //IMPRESION
    arch<<setw(50)<<"REPORTE DE FLOTA"<<endl;
    this->imprimirLinea(arch, '=');
    for(auto vehiculo:vflota){
        vehiculo.imprime(arch);
        arch<<endl;
    }
}

void Flota::imprimirLinea(ofstream& arch, char car){
    for(int i=0; i<MAXLINEA; i++) arch<<car;
    arch<<endl;
}

void Flota::cargaPedidos(const char* nomb){
    ifstream arch(nomb, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    int dniTemp, posCli;
    //33397650,IHG.413,3,4.8
    while(true){
        arch>>dniTemp;
        if(arch.eof()) break;
        arch.get();
        //BUSCAMOS
        posCli=this->buscarCliente(dniTemp);
        if(posCli!=NOTFOUND){
            vflota[posCli].agregarPedido(arch);
        }
        else while(arch.get()!='\n');
    }
}

int Flota::buscarCliente(int dni){
    for(int i=0; i<vflota.size(); i++){
        if(vflota[i].compararCliente(dni)) return i;
    }
    return NOTFOUND;
}



//FUNCIONES
