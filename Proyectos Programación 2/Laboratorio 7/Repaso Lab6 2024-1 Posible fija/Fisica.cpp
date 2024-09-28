/* 
 * File:   Fisica.cpp
 * Author: Lucas
 * 
 * Created on 30 de mayo de 2024, 19:41
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Fisica.h"

//CONST Y DEST
Fisica::Fisica() {
    profesor=nullptr;
}

Fisica::~Fisica() {
    if(profesor!=nullptr) delete profesor;
}

//GETTERS Y SETTERS
void Fisica::SetProfesor(char * cad) {
    if(profesor!=nullptr) delete profesor;
    profesor=new char[strlen(cad)+1];
    strcpy(profesor, cad);
}

void Fisica::GetProfesor(char * cad) const {
    if(profesor==nullptr) cad[0]=0;
    else strcpy(cad, profesor);
}

//METODOS
void Fisica::leer_datos(ifstream &arch){
    char prof[60];
    //LEEMOS
    Libro::leer_datos(arch);
    arch.get();
    arch.getline(prof, 60, '\n');
    //GUARDAMOS
    SetProfesor(prof);
}

void Fisica::imprimir(ofstream &arch){
    char prof[40];
    GetProfesor(prof);
    Libro::imprimir(arch);
    arch<<"Profesor: "<<prof<<endl<<endl;
}

//FUNCIONES
