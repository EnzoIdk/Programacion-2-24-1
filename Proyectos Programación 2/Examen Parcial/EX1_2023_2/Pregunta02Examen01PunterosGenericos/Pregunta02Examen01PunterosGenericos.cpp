/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>   
#include <cstring>
#include <cstdlib>

#include "Pregunta02Examen01PunterosGenericos.h"

using namespace std;

#define INCREMENTO 5

void cargarProductos(void *&prod,const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **productos,*reg;
    int numDat=0,cap=0;
    while(true){
        reg=leerRegProd(arch);
        if(arch.eof()) break;
        if(numDat==cap) aumentarCap(productos,numDat,cap);
        productos[numDat-1]=reg;
        numDat++;
    }
    prod=productos;
    qsort(prod,numDat-1,sizeof(void*),voidcmpCod);
}

int voidcmpCod(const void *a,const void *b){
    void **ai=(void**)a,**bi=(void**)b;
    void **regA=(void**)(*ai),**regB=(void**)(*bi);
    void **datosA=(void**)(regA[0]),**datosB=(void**)(regB[0]);
    char *codigoA=(char*)(datosA[0]),*codigoB=(char*)(datosB[0]);
    return strcmp(codigoA,codigoB);
}

void *leerRegProd(ifstream &arch){
    void **registro=new void*[2]{};
    void *datos=leerRegDatos(arch);
    if(arch.eof()) return nullptr;
    registro[0]=datos;
    registro[1]=nullptr;
    return registro;
}

void *leerRegDatos(ifstream &arch){
    void **registro=new void*[4]{};
    char *codigo,*descripcion,car;
    double *precio=new double;
    int *stock=new int;
    codigo=leerCadenaExacta(arch);
    if(arch.eof()) return nullptr;
    descripcion=leerCadenaExacta(arch);
    arch>>*precio>>car>>*stock;
    arch.get();
    registro[0]=codigo;
    registro[1]=descripcion;
    registro[2]=precio;
    registro[3]=stock;
    return registro;
}

char *leerCadenaExacta(ifstream &arch){
    char cadena[60],*ptr;
    arch.getline(cadena,60,',');
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void aumentarCap(void **&productos,int &numDat,int &cap){
    cap+=INCREMENTO;
    void **aux=new void*[cap]{};
    if(numDat==0) numDat=1;
    else{
        for(int i=0;i<numDat;i++) aux[i]=productos[i];
        delete productos;
    }
    productos=aux;
}

void pruebaDeCargaDeProductos(void *prod){
    ofstream arch("PruebaProductos.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo PruebaProductos.txt"<<endl;
        exit(1);
    }
    void **productos=(void**)prod;
    void **aux;
    for(int i=0;productos[i];i++){
        aux=(void**)productos[i];
        imprimirDatosProductos(arch,aux[0]);
    }
}

void imprimirDatosProductos(ofstream &arch,void *dat){
    void **datos=(void**)dat;
    char *codigo=(char*)datos[0],*desc=(char*)datos[1];
    double *precio=(double*)datos[2];
    int *stock=(int*)datos[3];
    arch<<codigo<<setw(3)<<' '<<left<<setw(60)<<desc<<right<<setw(10)<<
            *precio<<setw(10)<<*stock<<endl;
}
