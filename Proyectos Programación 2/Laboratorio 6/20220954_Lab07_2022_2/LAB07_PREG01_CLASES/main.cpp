/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 07:20 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "cita.h"
#include "medico.h"
#include "paciente.h"

int main(int argc, char** argv) {
    paciente pac;
    cita cit,cit2;
    ifstream archPac("Pacientes.csv",ios::in);
    if(not archPac.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pacientes.csv"<<endl;
        exit(1);
    }
    ifstream archMed("Medicos.csv",ios::in);
    if(not archMed.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Medicos.csv"<<endl;
        exit(1);
    }
    ifstream archCit("Citas.csv",ios::in);
    if(not archCit.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Citas.csv"<<endl;
        exit(1);
    }
    ofstream archRep("RepPacientes.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RepPacientes.txt"<<endl;
        exit(1);
    }
    medico arrMed[15];
    int n=15;
    for(int i=0;i<n;i++) archMed>>arrMed[i];
    archPac>>pac;
    archCit>>cit;
    archCit>>cit2;
    cit<=arrMed;
    cit2<=arrMed;
    pac+=cit;
    pac+=cit2;
    pac++;
    archRep<<pac;
    return 0;
}

