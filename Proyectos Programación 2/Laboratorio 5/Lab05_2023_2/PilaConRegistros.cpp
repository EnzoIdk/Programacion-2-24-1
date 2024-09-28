/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>        

using namespace std;

#include "PilaConEnteros.h"
#include "PilaConRegistros.h"
#include "FlotaGenerica.h"

enum Pedido{COD,DNI,CANT,PESO};
enum Pila{INICIO,PESOTOTAL};
enum Camion{DATO,SGTE};

void *leeregistro(ifstream &arch){
    void **registro=new void*[4]{};
    char *codigo,car;
    int *dni=new int,*cant=new int;
    double *peso=new double;
    codigo=leerCadena(arch);
    if(arch.eof()) return nullptr;
    arch>>*dni>>car>>*cant>>car>>*peso;
    arch.get();
    registro[COD]=codigo;
    registro[DNI]=dni;
    registro[CANT]=cant;
    registro[PESO]=peso;
    return registro;
}

char *leerCadena(ifstream &arch){
    char cadena[10],*ptr;
    arch.getline(cadena,10,',');
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

double calcularegistro(double pesomax,void *dato){
    void **aux=(void**)dato;
    double *peso=(double*)aux[PESO];
    return pesomax-*peso;
}

int cmpregistro(const void *dato1,const void *dato2){
    void **camion1=(void**)dato1,**camion2=(void**)dato2;
    void **pila1=(void**)camion1[DATO],**pila2=(void**)camion2[DATO];
    double *peso1=(double*)pila1[PESOTOTAL],*peso2=(double*)pila2[PESOTOTAL];
    return *peso2-*peso1;
}

void imprimeregistro(ofstream &arch,void *pila){
    void **ant,**dato;
    char *codigo;
    int *cantidad;
    double *peso;
    if(pila!=nullptr){
        ant=(void**)pila;
        imprimeregistro(arch,ant[SGTE]);
        dato=(void**)ant[DATO];
        codigo=(char*)dato[COD];
        cantidad=(int*)dato[CANT];
        peso=(double*)dato[PESO];
        arch<<setw(15)<<codigo<<setw(6)<<" "<<setw(2)<<*cantidad<<setw(8)<<*peso<<endl;
    }
}