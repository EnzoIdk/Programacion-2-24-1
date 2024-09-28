/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: Enzo
 * 
 * Created on 23 de mayo de 2024, 11:55 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Funciones.h"
#define NO_ENCONTRADO -1
#define TAM_LINEA 120

Funciones::Funciones() {
}

Funciones::Funciones(const Funciones& orig) {
}

Funciones::~Funciones() {
}

void Funciones::cargarMedicos(){
    ifstream archMed("Medicos.csv",ios::in);
    if(not archMed.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Medicos.csv"<<endl;
        exit(1);
    }
    int i=0;
    while(true){
        archMed>>arrMed[i];
        if(archMed.eof()) break;
        i++;
    }
}

void Funciones::cargarPacientes(){
    ifstream archPac("Pacientes.csv",ios::in);
    if(not archPac.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pacientes.csv"<<endl;
        exit(1);
    }
    int i=0;
    while(true){
        archPac>>arrPac[i];
        if(archPac.eof()) break;
        i++;
    }
}

void Funciones::cargarCitas(){
    ifstream archCit("Citas.csv",ios::in);
    if(not archCit.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Citas.csv"<<endl;
        exit(1);
    }
    cita cit;
    int posCli;
    while(true){
        archCit>>cit;
        if(archCit.eof()) break;
        posCli=buscarCli(arrPac,cit.GetDni());
        if(posCli!=NO_ENCONTRADO) arrPac[posCli]+=cit;
    }
}

int buscarCli(paciente *arr,int dni){
    for(int i=0;arr[i].GetDni();i++){
        if(dni==arr[i].GetDni()) return i;
    }
    return NO_ENCONTRADO;
}

void Funciones::actualizarTarifas(){
    for(int i=0;arrPac[i].GetDni();i++){
        arrPac[i].RegistrarTarifa(arrMed);
        arrPac[i]++;
    }
}

void Funciones::mostrarDatos(){
    ofstream archRep("ReporteFinal.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteFinal.txt"<<endl;
        exit(1);
    }
    for(int i=0;arrPac[i].GetDni();i++) archRep<<arrPac[i];
}
