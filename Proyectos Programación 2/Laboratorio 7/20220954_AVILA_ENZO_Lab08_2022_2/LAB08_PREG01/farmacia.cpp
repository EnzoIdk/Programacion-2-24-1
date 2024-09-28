/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   farmacia.cpp
 * Author: aml
 * 
 * Created on 29 de mayo de 2024, 09:26 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "farmacia.h"
#define NO_ENCONTRADO -1

void farmacia::cargamedico(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int nd=0,codigo;
    char nombre[60],especialidad[20];
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch.get();
        arch.getline(nombre,60,',');
        arch.getline(especialidad,20);
        lmedico[nd].SetCodigo(codigo);
        lmedico[nd].SetNombre(nombre);
        lmedico[nd].SetEspecialidad(especialidad);
        nd++;
    }
}

void farmacia::leerecetas(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int nS=0,nC=0,fecha,dni,codigoMed;
    char nombreCli[60],especialidad[20];
    while(true){
        leerDatosGenerales(arch,fecha,dni,nombreCli,codigoMed,especialidad);
        if(arch.eof()) break;
        leeRecetaCliente(arch,fecha,dni,nombreCli,codigoMed,especialidad,nS,nC);
    }
}

void farmacia::leerDatosGenerales(ifstream &arch,int &fecha,int &dni,
        char *nombreCli,int &codigoMed,char *especialidad){
    int dd,mm,aa;
    char car;
    arch>>dd;
    if(arch.eof()) return;
    arch>>car>>mm>>car>>aa>>car>>dni>>car;
    fecha=aa*10000+mm*100+dd;
    arch.getline(nombreCli,60,',');
    arch>>codigoMed>>car;
    int pos=buscarPosMed(codigoMed);
    if(pos!=NO_ENCONTRADO) lmedico[pos].GetEspecialidad(especialidad);
}

int farmacia::buscarPosMed(int cod){
    for(int i=0;lmedico[i].GetCodigo();i++){
        if(lmedico[i].GetCodigo()==cod) return i;
    }
    return NO_ENCONTRADO;
}

void farmacia::leeRecetaCliente(ifstream &arch,int fecha,int dni,const char *nombreCli,
        int codigoMed,const char *especialidad,int &nS,int &nC){
    int codMedicamento,cantidad;
    while(true){
        arch>>codMedicamento;
        arch.get();
        arch>>cantidad;
        if(conReceta(codMedicamento)){
            lconreceta[nC].asignarDatos(codMedicamento,cantidad,fecha,codigoMed,especialidad);
            nC++;
        }
        else{
            lsinreceta[nS].asignarDatos(codMedicamento,cantidad,fecha,dni,nombreCli);
            nS++;
        }
        if(arch.get()=='\n') return;
    }
}

bool farmacia::conReceta(int codigo){
    if((codigo/10000)%2==0) return true;
    else return false;
}

void farmacia::imprimirrecetas(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<"Codigo"<<setw(3)<<' '<<"Descripcion del Med."<<setw(10)<<' '<<
            "Cant."<<setw(5)<<' '<<"DNI"<<setw(10)<<' '<<"Nombre"<<endl;
    imprimirLinea(arch,120,'=');
    for(int i=0;lsinreceta[i].GetDni();i++){
        lsinreceta[i].imprimir(arch);
    }
    arch<<"Codigo"<<setw(3)<<' '<<"Descripcion del Med."<<setw(10)<<' '<<
            "Cant."<<setw(5)<<' '<<"Cod. Medico"<<setw(5)<<' '<<"Especialidad"<<endl;
    imprimirLinea(arch,120,'=');
    for(int i=0;lconreceta[i].GetCodmed();i++){
        lconreceta[i].imprimir(arch);
    }
}

void farmacia::imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}

