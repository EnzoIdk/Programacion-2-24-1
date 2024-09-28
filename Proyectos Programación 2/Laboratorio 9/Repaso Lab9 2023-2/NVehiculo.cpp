/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   NVehiculo.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 12:25
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "NVehiculo.h"
#include "Furgon.h"
#include "Camion.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

NVehiculo::NVehiculo() {
    unidad=nullptr;
}

NVehiculo::NVehiculo(const class NVehiculo &orig) {
    unidad=nullptr;
    *this=orig;
}

NVehiculo::~NVehiculo() {
    //SIN DESTRUCTOR
}

//GETTERS Y SETTERS

//METODOS
void NVehiculo::operator =(const class NVehiculo& orig){
    unidad=orig.unidad;
}

void NVehiculo::lee(ifstream& arch){
    char tipo;
    //C,20864087,O5L-856,1000,2,6
    arch>>tipo;
    if(arch.eof()) return;
    arch.get();
    //
    this->asignaVehiculo(tipo);
    //
    unidad->lee(arch);
}

void NVehiculo::asignaVehiculo(char tipo){
    switch(tipo){
        case 'F':
            unidad=new class Furgon;
            break;
        case 'C':
            unidad=new class Camion;
            break;
    }
}

void NVehiculo::imprime(ofstream& arch){
    unidad->imprime(arch);
}

//void NVehiculo::SetNull(){
//    unidad=nullptr;
//}

//FUNCIONES

bool NVehiculo::operator <(const class NVehiculo& dato) const{
    return unidad->GetCliente()<dato.unidad->GetCliente();
}

void NVehiculo::eliminar(){
    if(unidad!=nullptr) delete unidad;
}

bool NVehiculo::compararCliente(int dni) const{
    return unidad->GetCliente()==dni;
}

void NVehiculo::agregarPedido(ifstream& arch){
    char codPed[10];
    int cant;
    double peso;
    //IHG.413,3,4.8
    arch.getline(codPed, 10, ',');
    arch>>cant;
    arch.get();
    arch>>peso;
    unidad->cargaDeposito(codPed, cant, peso);
}
