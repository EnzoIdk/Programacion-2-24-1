/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Furgon.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 12:21
 */

#include <iostream>
#include <iomanip>
#include <iterator>
using namespace std;
#include <cstring>

#include "Furgon.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

Furgon::Furgon() {

}

Furgon::Furgon(const class Furgon &orig) {

}

Furgon::~Furgon() {

}

//GETTERS Y SETTERS
void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}

//METODOS
void Furgon::lee(ifstream& arch){
    int filasTemp, puertasTemp; 
    //LECUTRA
    this->Vehiculo::lee(arch);
    //1,3
    arch>>filasTemp;
    arch.get();
    arch>>puertasTemp;
    arch.get(); //\n
    //GUARDAMOS
    this->SetFilas(filasTemp);
    this->SetPuertas(puertasTemp);
}

void Furgon::imprime(ofstream& arch){
    this->Vehiculo::imprime(arch);
    //
    arch<<left<<setw(16)<<"#Filas: "<<this->GetFilas()<<endl;
    arch<<left<<setw(16)<<"#Puertas: "<<this->GetPuertas()<<endl;
    arch<<left<<setw(16)<<"Lista de Pedidos:"<<endl;
    for(auto pedido:vdeposito){
        arch<<setw(5)<<' ';
        pedido.imprimir(arch);
    }
}

void Furgon::cargaDeposito(char* codPed, int cant, double peso){
    vector<class NPedido>::iterator iterFur=vdeposito.begin();
    class NPedido temp;
    temp.SetPeso(peso);
    temp.SetCantidad(cant);
    temp.SetCodigo(codPed);
    //GUARDAR
    if(cant*peso<=this->GetMaxcarga()-this->GetActcarga()){
        vdeposito.insert(iterFur, temp);
//        vdeposito.push_back(temp);
        this->SetActcarga(this->GetActcarga()+cant*peso);
    }
}

//FUNCIONES
