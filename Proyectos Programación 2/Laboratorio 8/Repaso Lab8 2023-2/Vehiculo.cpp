/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Vehiculo.cpp
 * Author: aml
 * 
 * Created on 12 de junio de 2024, 12:22 PM
 */

#include <iomanip>
using namespace std;
#include <cstring>

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    placa=nullptr;
    ped=nullptr;
    actcarga=0;
}

Vehiculo::~Vehiculo() {
    if(placa!=nullptr) delete placa;
    //ELIMINA PILA
    
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(char * cad) {
    if(placa!=nullptr) delete placa;
    placa=new char[strlen(cad)+1];
    strcpy(placa, cad);
}

void Vehiculo::GetPlaca(char * cad) const {
    if(placa==nullptr) cad[0]=0;
    else strcpy(cad, placa);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::lee(ifstream &arch){
    char temp[10];
    //94326707,U3F-754,1000,2,8
    arch>>cliente;
    arch.get();
    arch.getline(temp, 10, ',');
    arch>>maxcarga;
    arch.get();
    //GUARDAMOS
    this->SetPlaca(temp);
}

void Vehiculo::imprime(ofstream &arch){
    arch<<"Codigo Cliente:"<<setw(10)<<cliente<<endl;
    arch<<"Placa:"<<setw(10)<<placa<<endl;
    arch<<"Carga Maxima:"<<setw(10)<<maxcarga<<endl;
    arch<<"Carga Actual:"<<setw(10)<<actcarga<<endl;
}

void Vehiculo::crearPedido(char * idPed, int cantTemp, double pesoTemp){
    class NPedido * nuevo=new NPedido;
    nuevo->setDatos(idPed, cantTemp, pesoTemp);
    if(maxcarga>=actcarga+pesoTemp*cantTemp){
        if(ped==nullptr){
            ped=nuevo;
        }
        else{
            nuevo->sig=ped;
            ped=nuevo;
        }   
        actcarga+=pesoTemp*cantTemp;
    }
}

void Vehiculo::imprimePedidos(ofstream &arch){
    class NPedido * aux=ped;
    while(aux){
        aux->imprime(arch);
        aux=aux->sig;
    }
}