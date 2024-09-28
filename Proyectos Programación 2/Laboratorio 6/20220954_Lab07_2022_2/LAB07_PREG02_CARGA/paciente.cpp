/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   paciente.cpp
 * Author: Enzo
 * 
 * Created on 23 de mayo de 2024, 07:35 AM
 */

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "paciente.h"
#include "cita.h"
#define TAM_LINEA 60

paciente::paciente() {
    nombre=nullptr;
    dni=0;
    totalgastado=0;
}

paciente::paciente(const paciente& orig) {
}

paciente::~paciente() {
    if(nombre!=nullptr) delete nombre;
}

void paciente::SetTotalgastado(double totalgastado) {
    this->totalgastado = totalgastado;
}

double paciente::GetTotalgastado() const {
    return totalgastado;
}

void paciente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int paciente::GetTelefono() const {
    return telefono;
}

void paciente::SetNombre(const char *nomb) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void paciente::GetNombre(char *nomb) const {
    if(nombre==nullptr) nomb[0]=0;
    else strcpy(nomb,nombre);
}

void paciente::SetDni(int dni) {
    this->dni = dni;
}

int paciente::GetDni() const {
    return dni;
}

void operator >>(ifstream &arch,paciente &pac){
    int dni,telefono;
    char nombre[60];
    arch>>dni;
    if(arch.eof()) return;
    arch.get();
    arch.getline(nombre,60,',');
    arch>>telefono;
    pac.SetDni(dni);
    pac.SetNombre(nombre);
    pac.SetTelefono(telefono);
}

void paciente::operator +=(const class cita &cit){
    double tarifa=cit.GetTarifa();
    int numCitas;
    for(numCitas=0;lcitas[numCitas].GetDni();numCitas++);
    lcitas[numCitas].SetDni(cit.GetDni());
    lcitas[numCitas].SetCodigo(cit.GetCodigo());
    lcitas[numCitas].SetFecha(cit.GetFecha());
    lcitas[numCitas].SetTarifa(tarifa);
}

void paciente::operator ++(int){
    int numCitas;
    for(numCitas=0;lcitas[numCitas].GetDni();numCitas++);
    for(int i=0;i<numCitas;i++){
        totalgastado+=lcitas[i].GetTarifa();
    }
}

void operator <<(ofstream &arch,paciente &pac){
    char nombre[60];
    pac.GetNombre(nombre);
    arch<<setprecision(2)<<fixed;
    arch<<"DNI"<<setw(11)<<' '<<"NOMBRE"<<setw(20)<<' '<<"TELEFONO"<<endl;
    arch<<pac.GetDni()<<setw(6)<<' '<<left<<setw(25)<<nombre<<right<<setw(10)<<
            pac.GetTelefono()<<endl;
    arch<<"RELACION DE CITAS"<<endl;
    arch<<"No. "<<setw(3)<<' '<<"FECHA"<<setw(4)<<' '<<"CODIGO DEL MEDICO"<<
            setw(10)<<' '<<"TARIFA"<<endl;
    pac.ImprimirCitas(arch);
}

void paciente::ImprimirCitas(ofstream &arch){
    int numCitas;
    for(numCitas=0;lcitas[numCitas].GetDni();numCitas++);
    for(int i=0;i<numCitas;i++){
        arch<<i+1<<')'<<setw(2)<<' ';
        imprimirFecha(arch,lcitas[i].GetFecha());
        arch<<lcitas[i].GetCodigo()<<setw(21)<<lcitas[i].GetTarifa()<<endl;
    }
    arch<<"MONTO TOTAL GASTADO: "<<setw(10)<<totalgastado<<endl;
    imprimirLinea(arch,TAM_LINEA,'=');
}

void imprimirFecha(ofstream &arch,int fecha){
    int dd,mm,aa;
    aa=fecha/10000;
    mm=(fecha/100)%100;
    dd=fecha%100;
    arch<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa<<
            setfill(' ')<<setw(8)<<' ';
}

void imprimirLinea(ofstream &arch,int longitud,char simb){
    for(int i=0;i<longitud;i++) arch.put(simb);
    arch<<endl;
}

void paciente::RegistrarTarifa(medico *arr){
    int numCitas;
    for(numCitas=0;lcitas[numCitas].GetDni();numCitas++);
    for(int i=0;i<numCitas;i++) lcitas[i]<=arr;
}