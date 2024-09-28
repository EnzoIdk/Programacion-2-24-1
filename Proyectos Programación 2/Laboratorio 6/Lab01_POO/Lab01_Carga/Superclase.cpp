/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Superclase.cpp
 * Author: Enzo
 * 
 * Created on 23 de mayo de 2024, 11:11 PM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Superclase.h"
#include "LibroPedido.h"
#include "AperturaDeArchivos.h"

using namespace std;

#define NO_ENCONTRADO -1

Superclase::Superclase() {
}

Superclase::Superclase(const Superclase& orig) {
}

Superclase::~Superclase() {
}

void Superclase::cargarLibros(){
    ifstream archLib;
    AperturaDeUnArchivoDeTextosParaLeer(archLib,"Libros.csv");
    for(int i=0;archLib>>arrLibros[i];i++);
}

void Superclase::cargarClientes(){
    ifstream archCli;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Cientes.csv");
    for(int i=0;archCli>>arrClientes[i];i++);
}

void Superclase::leerPedidos(){
    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.txt");
    int numPed,dni,posCli;
    char codigo[8],car;
    LibroPedido ped;
    while(true){
        archPed>>numPed;
        if(archPed.eof()) break;
        archPed>>car>>dni>>car;
        posCli=buscarCli(arrClientes,dni);
        if(posCli!=NO_ENCONTRADO){
            while(true){
                archPed>>codigo;
                ped.SetNumPedido(numPed);
                ped.SetCodLibro(codigo);
                ped>>arrLibros;
                arrClientes[posCli]<<ped;
                if(archPed.get()=='\n') break;
            }
            ++arrClientes[posCli];
        }
        else while(archPed.get()!='\n');
    }
}

int buscarCli(Cliente *arrCli,int dni){
    for(int i=0;arrCli[i].GetDni();i++){
        if(dni==arrCli[i].GetDni()) return i;
    }
    return NO_ENCONTRADO;
}

void Superclase::emitirReporte(){
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,"Reporte.txt");
    char codigo[8];
    int i=0;
    imprimirLinea(archRep,130,'=');
    archRep<<"REPORTE DE LIBROS"<<endl;
    imprimirLinea(archRep,130,'=');
    while(true){
        arrLibros[i].GetCodigo(codigo);
        if(strcmp(codigo,"FIN")==0) break;
        archRep<<arrLibros[i];
        i++;
    }
    imprimirLinea(archRep,40,'=');
    archRep<<"REPORTE DE CLIENTES"<<endl;
    imprimirLinea(archRep,40,'=');
    for(int j=0;arrClientes[j].GetDni();j++){
        archRep<<arrClientes[j];
        imprimirLinea(archRep,40,'-');
    }
}

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}
