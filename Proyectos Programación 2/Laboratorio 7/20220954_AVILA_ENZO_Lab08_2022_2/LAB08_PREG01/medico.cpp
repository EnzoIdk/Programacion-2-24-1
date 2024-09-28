/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medico.cpp
 * Author: Enzo
 * 
 * Created on 29 de mayo de 2024, 08:43 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "medico.h"

medico::medico() {
    especialidad=nullptr;
    nombre=nullptr;
    codigo=0;
}

medico::~medico() {
    if(especialidad!=nullptr) delete especialidad;
    if(nombre!=nullptr) delete nombre;
}

void medico::SetEspecialidad(const char *esp) {
    if(especialidad!=nullptr) delete especialidad;
    especialidad=new char[strlen(esp)+1];
    strcpy(especialidad,esp);
}

void medico::GetEspecialidad(char *esp) const {
    if(especialidad==nullptr) esp[0]=0;
    else strcpy(esp,especialidad);
}

void medico::SetNombre(const char *nomb) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void medico::GetNombre(char *nomb) const {
    if(nombre==nullptr) nomb[0]=0;
    else strcpy(nomb,nombre);
}

void medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medico::GetCodigo() const {
    return codigo;
}

