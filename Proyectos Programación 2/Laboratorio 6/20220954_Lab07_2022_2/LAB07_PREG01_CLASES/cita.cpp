/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   cita.cpp
 * Author: Enzo
 * 
 * Created on 23 de mayo de 2024, 07:36 AM
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "cita.h"

cita::cita() {
    /*se inicializan en 0 al construir*/
    dni=0; 
    tarifa=0;
}

cita::cita(const cita& orig) {
}

cita::~cita() {
}

void cita::SetTarifa(double tarifa) {
    this->tarifa = tarifa;
}

double cita::GetTarifa() const {
    return tarifa;
}

void cita::SetFecha(int fecha) {
    this->fecha = fecha;
}

int cita::GetFecha() const {
    return fecha;
}

void cita::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int cita::GetCodigo() const {
    return codigo;
}

void cita::SetDni(int dni) {
    this->dni = dni;
}

int cita::GetDni() const {
    return dni;
}

void operator >>(ifstream &arch,cita &cit){
    int dni,codigo;
    int dd,mm,aa,fecha;
    char car;
    arch>>dni;
    if(arch.eof()) return;
    arch>>car>>codigo>>car>>dd>>car>>mm>>car>>aa;
    fecha=aa*10000+mm*100+dd;
    cit.SetDni(dni);
    cit.SetCodigo(codigo);
    cit.SetFecha(fecha);
}

void cita::operator <=(const class medico *arr){
    for(int i=0;arr[i].GetCodigo();i++){
        if(codigo==arr[i].GetCodigo()){
            tarifa=arr[i].GetTarifa();
            break;
        }
    }
}