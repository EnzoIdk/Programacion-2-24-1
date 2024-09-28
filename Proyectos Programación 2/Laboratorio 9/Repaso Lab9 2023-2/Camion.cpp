/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Camion.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 12:15
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Camion.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

Camion::Camion() {

}

Camion::Camion(const class Camion &orig) {

}

Camion::~Camion() {

}

//GETTERS Y SETTERS
void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

//METODOS
void Camion::lee(ifstream& arch){
    int ejesTemp, llantasTemp;
    //LECUTRA
    this->Vehiculo::lee(arch);
    //2,6
    arch>>ejesTemp;
    arch.get();
    arch>>llantasTemp;
    arch.get(); //\n
    //GUARDAMOS
    this->SetEjes(ejesTemp);
    this->SetLlantas(llantasTemp);
}

void Camion::imprime(ofstream& arch){
    int numPed=1;
    this->Vehiculo::imprime(arch);
    //
    arch<<left<<setw(16)<<"#Ejes: "<<right<<this->GetEjes()<<endl;
    arch<<left<<setw(16)<<"#Llantas: "<<right<<this->GetLlantas()<<endl;
    arch<<left<<setw(16)<<"Lista de Pedidos:"<<right<<endl;
    for(auto pedido:vdeposito){
        arch<<setw(5)<<numPed;
        pedido.imprimir(arch);
        numPed++;
    }
}

void Camion::cargaDeposito(char* codPed, int cant, double peso){
    class NPedido temp;
    temp.SetPeso(peso);
    temp.SetCantidad(cant);
    temp.SetCodigo(codPed);
    //GUARDAR
    if(cant*peso<=this->GetMaxcarga()-this->GetActcarga() and 
            vdeposito.size()<5){
        vdeposito.push_back(temp);
        this->SetActcarga(this->GetActcarga()+cant*peso);
    }
}

//FUNCIONES
