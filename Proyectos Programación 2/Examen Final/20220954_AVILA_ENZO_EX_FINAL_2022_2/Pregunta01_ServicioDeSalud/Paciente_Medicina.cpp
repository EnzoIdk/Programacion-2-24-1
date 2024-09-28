/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Paciente_Medicina.cpp
 * Author: Enzo
 * 
 * Created on 8 de julio de 2024, 07:26 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Paciente_Medicina.h"
#include "Paciente.h"
#include "Medicina_Cantidad.h"
using namespace std;

Paciente_Medicina::Paciente_Medicina() {
    totalDeGastos=0;
}

Paciente_Medicina::Paciente_Medicina(const Paciente_Medicina& orig) {
    paciente=orig.paciente;
    medicina_cantidad=orig.medicina_cantidad;
    totalDeGastos=orig.totalDeGastos;
}

Paciente_Medicina::~Paciente_Medicina() {
}

void Paciente_Medicina::SetTotalDeGastos(double totalDeGastos) {
    this->totalDeGastos = totalDeGastos;
}

double Paciente_Medicina::GetTotalDeGastos() const {
    return totalDeGastos;
}

int Paciente_Medicina::obtenerDNI() const{
    return paciente.getDni();
}

void Paciente_Medicina::SetPaciente(const class Paciente &orig){
    paciente=orig;
}

void Paciente_Medicina::leerMedicinas(ifstream& arch){
    class Medicina_Cantidad auxMedCant;
    list<Medicina_Cantidad>::iterator it;
    while(true){
        arch>>auxMedCant;
        for(it=medicina_cantidad.begin();it!=medicina_cantidad.end();it++)
            if((*it).GetCodigo()==auxMedCant.GetCodigo()) break;
        if(it==medicina_cantidad.end())
            medicina_cantidad.push_back(auxMedCant);
        else
            (*it).SetCantidad((*it).GetCantidad()+auxMedCant.GetCantidad());
        if(arch.get()=='\n') break;
    }
}

bool Paciente_Medicina::operator >(const class Paciente &orig){
    return paciente.getFechaUltimaConsulta()>orig.getFechaUltimaConsulta();
}

void Paciente_Medicina::totalizar(map<int,Medicina> med){
    for(auto aux:medicina_cantidad){
        for(auto auxMapa:med){
            if(aux.GetCodigo()==auxMapa.second.GetCodigo())
                totalDeGastos+=auxMapa.second.GetPrecio();
        }
    }
}

void Paciente_Medicina::imprimir(ofstream& arch){
    for(int i=0;i<120;i++) arch.put('=');
    arch<<endl;
    paciente.imprimirPaciente(arch);
    arch<<"Total de gastos: "<<totalDeGastos<<endl;
    arch<<"Listado de medicamentos: "<<endl;
    for(auto aux:medicina_cantidad){
        arch<<aux.GetCodigo()<<' '<<aux.GetCantidad()<<endl;
    }
}