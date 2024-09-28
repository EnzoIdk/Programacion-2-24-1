/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ServicioDeSalud.cpp
 * Author: Enzo
 * 
 * Created on 8 de julio de 2024, 07:36 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Paciente.h"
using namespace std;
#include "ServicioDeSalud.h"
#include "Medicina.h"

#include "Paciente_Medicina.h"

ServicioDeSalud::ServicioDeSalud() {
}

ServicioDeSalud::ServicioDeSalud(const ServicioDeSalud& orig) {
}

ServicioDeSalud::~ServicioDeSalud() {
}

void ServicioDeSalud::leerMedicinas(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Medicina dato;
    while(true){
        arch>>dato;
        if(arch.eof()) break;
        medicina[dato.GetCodigo()]=dato;
    }
}

void ServicioDeSalud::imprimirMedicinas(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for(auto aux:medicina){
        arch<<aux.second;
    }
}

void ServicioDeSalud::leerConsultas(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Paciente pacAux;
    class Paciente_Medicina auxPacMed;
    list<Paciente_Medicina>::iterator it;
    while(true){
        pacAux.leerPaciente(arch);
        if(arch.eof()) break;
        
        for(it=paciente_medicina.begin();it!=paciente_medicina.end();it++)
            if(it->obtenerDNI()==pacAux.getDni()) break;
        if(it==paciente_medicina.end()){
            auxPacMed.SetPaciente(pacAux);
            auxPacMed.leerMedicinas(arch);
            paciente_medicina.push_back(auxPacMed);
        }
        else{
            //si ya se encuentra el paciente
            if(*it>pacAux){
                (*it).SetPaciente(pacAux);
            }
            (*it).leerMedicinas(arch);
        }
    }
}

void ServicioDeSalud::totalizar(){
    for(auto &aux:paciente_medicina){
        aux.totalizar(medicina);
    }
}

void ServicioDeSalud::imprimePacientes(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for(auto aux:paciente_medicina){
        aux.imprimir(arch);
    }
}