/* 
 * File:   Ficha.cpp
 * Author: Lucas
 * 
 * Created on 8 de junio de 2024, 21:32
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>

#include "Ficha.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
Ficha::Ficha() {
    id=nullptr;
}

Ficha::Ficha(const class Ficha &orig) {
    
}

Ficha::~Ficha() {
    if(id!=nullptr) delete id;
}

//GETTERS Y SETTERS
void Ficha::SetColumna(int columna) {
    this->columna = columna;
}

int Ficha::GetColumna() const {
    return columna;
}

void Ficha::SetFila(int fila) {
    this->fila = fila;
}

int Ficha::GetFila() const {
    return fila;
}

void Ficha::SetId(char * cad) {
    if(id!=nullptr) delete id;
    id=new char[strlen(cad)+1]{};
    strcpy(id, cad);
}

void Ficha::GetId(char * cad) const {
    if(id==nullptr) cad[0]=0;
    else strcpy(cad, id);
}

//METODOS
void Ficha::asignar(char * id, int fila, int columna){
    SetId(id);
    SetFila(fila);
    SetColumna(columna);
}

void Ficha::imprimirDatos(ofstream &arch){
    char idTemp[5];
    this->GetId(idTemp);
    //IMPRESION
    arch<<setw(5)<<idTemp<<setw(5)<<fila<<setw(5)<<columna<<endl;
}

//FUNCIONES
