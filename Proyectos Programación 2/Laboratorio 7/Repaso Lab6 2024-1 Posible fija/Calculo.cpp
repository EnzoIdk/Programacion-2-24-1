/* 
 * File:   Calculo.cpp
 * Author: Lucas
 * 
 * Created on 30 de mayo de 2024, 19:44
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Calculo.h"

//CONST Y DEST
Calculo::Calculo() {

}

Calculo::~Calculo() {

}

//GETTERS Y SETTERS
void Calculo::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Calculo::GetCiclo() const {
    return ciclo;
}

//METODOS
void Calculo::leer_datos(ifstream &arch){
    int ciclo;
    //LEEMOS
    Libro::leer_datos(arch);
    arch>>ciclo;
    arch.get(); //\n
    //GUARDAMOS
    SetCiclo(ciclo);
}

void Calculo::imprimir(ofstream &arch){
    Libro::imprimir(arch);
    arch<<"Ciclo: "<<setw(6)<<ciclo<<endl<<endl;
}

//FUNCIONES
