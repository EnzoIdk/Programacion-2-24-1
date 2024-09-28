/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ListaPacientes.cpp
 * Author: Enzo
 * 
 * Created on 13 de junio de 2024, 10:55 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaPacientes.h"
#include "NodoPaciente.h"
#include "Paciente.h"
#include "Emergencia.h"
#include "Ambulatorio.h"
#include "Urgencia.h"

ListaPacientes::ListaPacientes() {
    lista=nullptr;
}

ListaPacientes::~ListaPacientes() {
    elimina();
}

void ListaPacientes::elimina(){
    class NodoPaciente *sale;
    while(lista){
        sale=lista;
        lista=lista->sig;
        delete sale;
    }
    lista=nullptr;
}

void ListaPacientes::crealista(const char* nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Paciente *aux;
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        asignaMemoria(aux,tipo);
        aux->lee(arch);
        insertar(aux);
    }
}

void ListaPacientes::asignaMemoria(class Paciente *&aux, char tipo){
    switch(tipo){
        case 'E':
            aux=new class Emergencia;
            break;
        case 'A':
            aux=new class Ambulatorio;
            break;
        case 'U':
            aux=new class Urgencia;
            break;
    }
}

void ListaPacientes::insertar(class Paciente *aux){
    class NodoPaciente *rec=lista,*ant=nullptr,*nuevoNodo;
    nuevoNodo=new class NodoPaciente;
    nuevoNodo->ptrPaciente=aux;
    while(rec){
        if(aux->getPrioridad() < rec->ptrPaciente->getPrioridad()) break;
        ant=rec;
        rec=rec->sig;
    }
    nuevoNodo->sig=rec;
    if(ant!=nullptr) ant->sig=nuevoNodo;
    else lista=nuevoNodo;
}

void ListaPacientes::imprimelista(const char* nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class NodoPaciente *rec=lista;
    int prioridad=0,cantSeg=0,cont;
    arch<<setprecision(2)<<fixed;
    arch<<setw(40)<<' '<<"INSTITUTO DE SALUD S.A."<<endl;
    while(rec){
        if(rec->ptrPaciente->tieneSeguro()) cantSeg++;
        if(prioridad!=rec->ptrPaciente->getPrioridad()){
            prioridad=rec->ptrPaciente->getPrioridad();
            if(prioridad==1) encabezado1(arch);
            else if(prioridad==2) encabezado2(arch);
            else encabezado3(arch);
            cont=0;
        }
        cont++;
        arch<<setw(3)<<cont<<')'<<setw(3)<<' ';
        rec->ptrPaciente->imprime(arch);
        rec=rec->sig;
    }
    imprimirLinea(arch,120,'=');
    arch<<"Atendidos por seguro: "<<cantSeg<<endl;
}

void ListaPacientes::imprimirLinea(ofstream &arch,int tam,char simb){
    for(int i=0;i<tam;i++) arch.put(simb);
    arch<<endl;
}

void ListaPacientes::encabezado1(ofstream &arch){
    imprimirLinea(arch,120,'=');
    arch<<setw(30)<<' '<<"PACIENTES ATENDIDOS DE MANERA AMBULATORIA"<<endl;
    imprimirLinea(arch,120,'-');
    arch<<"No."<<setw(4)<<' '<<"DNI"<<setw(7)<<' '<<"Paciente"<<setw(40)<<
            ' '<<"Medico"<<setw(7)<<' '<<"% por Seg."<<endl;
}

void ListaPacientes::encabezado2(ofstream &arch){
    imprimirLinea(arch,120,'=');
    arch<<setw(30)<<' '<<"PACIENTES ATENDIDOS POR URGENCIA"<<endl;
    imprimirLinea(arch,120,'-');
    arch<<"No."<<setw(4)<<' '<<"DNI"<<setw(7)<<' '<<"Paciente"<<setw(40)<<
            ' '<<"Medico"<<setw(7)<<' '<<"% por Seg."<<setw(5)<<' '<<"% Urgencia"<<endl;
}

void ListaPacientes::encabezado3(ofstream &arch){
    imprimirLinea(arch,120,'=');
    arch<<setw(30)<<' '<<"PACIENTES ATENDIDOS POR EMERGENCIA"<<endl;
    imprimirLinea(arch,120,'-');
    arch<<"No."<<setw(4)<<' '<<"DNI"<<setw(7)<<' '<<"Paciente"<<setw(40)<<
            ' '<<"Medico"<<setw(15)<<' '<<"Referencia"<<endl;
}