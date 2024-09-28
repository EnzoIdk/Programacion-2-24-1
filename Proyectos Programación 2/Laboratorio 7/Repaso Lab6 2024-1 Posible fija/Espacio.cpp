/* 
 * File:   Espacio.cpp
 * Author: Lucas
 * 
 * Created on 30 de mayo de 2024, 19:55
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "Espacio.h"

//CONST Y DEST
Espacio::Espacio() {
    contenido=' ';
}

Espacio::~Espacio() {

}

//GETTERS Y SETTERS
void Espacio::SetPosy(int posy) {
    this->posy = posy;
}

int Espacio::GetPosy() const {
    return posy;
}

void Espacio::SetPosx(int posx) {
    this->posx = posx;
}

int Espacio::GetPosx() const {
    return posx;
}

void Espacio::SetContenido(char contenido) {
    this->contenido = contenido;
}

char Espacio::GetContenido() const {
    return contenido;
}

//METODOS
void Espacio::imprimir(ofstream &arch){
    arch<<"[ "<<contenido<<" ]";
}

//FUNCIONES
