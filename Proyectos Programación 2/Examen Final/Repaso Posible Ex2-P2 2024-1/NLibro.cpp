/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   NLibro.cpp
 * Author: Lucas
 * 
 * Created on 8 de julio de 2024, 07:50 PM
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "NLibro.h"
#include "Novela.h"
#include "Revista.h"
#include "Enciclopedia.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR

NLibro::NLibro() {
    plibro=nullptr;
}

NLibro::NLibro(const class NLibro &orig) {
    *this=orig;
}

NLibro::~NLibro() {

}

//GETTERS Y SETTERS

//METODOS
void NLibro::operator =(const class NLibro &orig){
    plibro=orig.plibro;
}

void NLibro::leer(ifstream &arch){
    char tipo;
    //N,Confesiones de una mascara,80,0.8,Yukio Mishima
    arch>>tipo;
    if(arch.eof()) return;
    arch.get(); //,
    this->asignarLibro(tipo);
    //
    plibro->leer(arch);
}

void NLibro::asignarLibro(char tipo){
    switch(tipo){
        case 'N':
            plibro=new class Novela;
            break;
        case 'R':
            plibro=new class Revista;
            break;
        case 'E':
            plibro=new class Enciclopedia;
            break;
    }
}

double NLibro::GetPeso() const{
    return plibro->GetPeso();
}

void NLibro::imprimir(ofstream &arch) const{
    plibro->imprimir(arch);
}

void NLibro::actualiza(int aa){
    plibro->actualiza(aa);
}
