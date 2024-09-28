/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   NLibro.cpp
 * Author: Lucas
 * 
 * Created on 20 de junio de 2024, 21:22
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "NLibro.h"
#include "Revista.h"
#include "Novela.h"
#include "Enciclopedia.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

NLibro::NLibro() {
    plibro=nullptr;
}

NLibro::NLibro(const class NLibro &orig) {
    plibro=nullptr;
    *this=orig;
}

NLibro::~NLibro() {
    //
}

//GETTERS Y SETTERS

//METODOS
void NLibro::operator =(const class NLibro& orig){
    plibro=orig.plibro;
}

void NLibro::leer(ifstream& arch){
    char tipo;
    //E,LA ENCICLOPEDIA DE LOS DINOSAURIOS,448,2,36225,2018
    arch>>tipo;
    if(arch.eof()) return;
    arch.get();
    this->asignarLibro(tipo);
    plibro->lee(arch);
}

void NLibro::asignarLibro(char tipo){
    switch(tipo){
        case 'R':
            plibro=new class Revista;
            break;
        case 'N':
            plibro=new class Novela;
            break;
        case 'E':
            plibro=new class Enciclopedia;
            break;
    }
}

double NLibro::GetPeso() const{
    return plibro->GetPeso();
}

void NLibro::eliminar(){
    if(plibro!=nullptr) delete plibro;
}

void NLibro::actualiza(){
    plibro->actualiza();
}

void NLibro::imprime(ofstream& arch){
    plibro->imprime(arch);
}

//FUNCIONES
