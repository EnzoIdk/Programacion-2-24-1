/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "ListaConRegistrosVoid.h"
enum Reg{COD,NOMB,SUE};
        
void *leeReg(ifstream &arch){
    void **registro=new void*[3];
    int *cod=new int;
    char *nombre;
    double *sueldo=new double;
    arch>>*cod;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre=leerCadena(arch);
    arch>>*sueldo;
    registro[COD]=cod;
    registro[NOMB]=nombre;
    registro[SUE]=sueldo;
    return registro;
}

char *leerCadena(ifstream &arch){
    char cad[60],*ptr;
    arch.getline(cad,60,',');
    ptr=new char[strlen(cad)+1];
    strcpy(ptr,cad);
    return ptr;
}

int regCodcmp(const void *a,const void *b){
    //apuntamos al registro
    void **reg1=(void**)a,**reg2=(void**)b;
    int *cod1=(int*)reg1[COD],*cod2=(int*)reg2[COD];
    return *cod1-*cod2;
}

int regNombcmp(const void *a,const void *b){
    void **reg1=(void**)a,**reg2=(void**)b;
    char *cad1=(char*)reg1[NOMB],*cad2=(char*)reg2[NOMB];
    return strcmp(cad1,cad2);
}

int regSuelcmp(const void *a,const void *b){
    void **reg1=(void**)a,**reg2=(void**)b;
    double *sueldo1=(double*)reg1[SUE],*sueldo2=(double*)reg2[SUE];
    return *sueldo2-*sueldo1;
}

void imprimeReg(void *reg){
    void **registro=(void**)reg;
    int *cod=(int*)registro[COD];
    char *nombre=(char*)registro[NOMB];
    double *sueldo=(double*)registro[SUE];
    cout<<setprecision(2)<<fixed;
    cout<<setw(10)<<*cod<<' '<<left<<setw(50)<<nombre<<right<<setw(10)<<
            *sueldo<<endl;
}

void eliminaReg(void *reg){
    void **registro=(void**)reg;
    int *cod=(int*)registro[COD];
    char *nombre=(char*)registro[NOMB];
    double *sueldo=(double*)registro[SUE];
    delete cod;
    delete nombre;
    delete sueldo;
    delete registro;
}