/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>  
#include <cstring>

using namespace std;

#include "PilaConRegistros.h"
enum Reg{COD,NOMB,PESO};

void *leeregistro(ifstream &arch){
    void **registro=new void*[3];
    int *codigo=new int;
    char *nombre;
    double *peso=new double;
    arch>>*codigo;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre=leerCadena(arch);
    arch>>*peso;
    registro[COD]=codigo;
    registro[NOMB]=nombre;
    registro[PESO]=peso;
    return registro;
}

char *leerCadena(ifstream &arch){
    char cadena[60],*ptr;
    arch.getline(cadena,60,',');
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

int cmpregistro(const void *a,const void *b){
    void **ai=(void**)a,**bi=(void**)b;
    void **regA=(void**)(*ai),**regB=(void**)(*bi);
    double *pesoA=(double*)regA[PESO],*pesoB=(double*)regB[PESO];
    return *pesoB-*pesoA;
}

void imprimeregistro(ofstream &arch,void *reg){
    void **registro=(void**)reg;
    int *codigo=(int*)registro[COD];
    char *nombre=(char*)registro[NOMB];
    double *peso=(double*)registro[PESO];
//    if(reg[0]==nullptr){
//        arch<<"CODIGO"<<setw(10)<<' '<<"Descripcion"<<setw(10)<<' '<<"Peso"<<endl;
//    }
    arch<<*codigo<<setw(3)<<' '<<left<<setw(50)<<nombre<<right<<setw(10)<<*peso<<endl;
}