/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "FuncionesVoid.h"

void leerDatos(void *&pers,int &nd,const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **personal,*buffer[100];
    nd=0;
    while(true){
        buffer[nd]=leerReg(arch);
        if(arch.eof()) break;
        nd++;
    }
    personal=new void*[nd+1]{};
    for(int i=0;i<nd;i++) personal[i]=buffer[i];
    pers=personal;
}

void *leerReg(ifstream &arch){
    void **registro=new void*[3];
    int *codigo=new int;
    char *nombre;
    double *sueldo=new double;
    arch>>*codigo;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre=leerCad(arch);
    arch>>*sueldo;
    registro[0]=codigo;
    registro[1]=nombre;
    registro[2]=sueldo;
    return registro;
}

char *leerCad(ifstream &arch){
    char cad[60],*ptr;
    arch.getline(cad,60,',');
    ptr=new char[strlen(cad)+1];
    strcpy(ptr,cad);
    return ptr;
}

int voidcmpSueldo(const void *a,const void *b){
    void **ai=(void**)a,**bi=(void**)b;
    void **regA=(void **)(*ai),**regB=(void**)(*bi);
    double *sueldoA=(double*)regA[2],*sueldoB=(double*)regB[2];
    return *sueldoA-*sueldoB;
}

int voidcmpNombre(const void *a,const void *b){
    void **ai=(void**)a,**bi=(void**)b;
    void **regA=(void**)(*ai),**regB=(void**)(*bi);
    char *nombA=(char*)regA[1],*nombB=(char*)regB[1];
    return strcmp(nombA,nombB);
}

void imprimirDatos(void *per,int nd){
    void **personal=(void**)per;
    cout<<setprecision(2)<<fixed;
    for(int i=0;i<nd;i++){
        imprimirPersona(personal[i]);
    }
}

void imprimirPersona(void *per){
    void **persona=(void**)per;
    int *codigo=(int*)persona[0];
    char *nombre=(char*)persona[1];
    double *sueldo=(double*)persona[2];
    cout<<*codigo<<' '<<left<<setw(40)<<nombre<<right<<setw(10)<<*sueldo<<endl;
}