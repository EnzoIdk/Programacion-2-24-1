/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>  
#include <cstring>

#include "Pregunta01Examen01PunterosMultiples.h"
using namespace std;
#define INCREMENTO 5

void cargarPedidos(int **&fechaCliCant,char **&codigoProd,const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int fecha,dni,cant,numDat=0,cap=0;
    char *codigo;
    while(true){
        leerDatos(arch,fecha,dni,cant,codigo);
        if(arch.eof()) break;
        if(numDat==cap) aumentarCap(fechaCliCant,codigoProd,numDat,cap);
        fechaCliCant[numDat-1]=asignarInt(fecha,dni,cant);
        codigoProd[numDat-1]=codigo;
        numDat++;
    }
    qsort(fechaCliCant,codigoProd,0,numDat-2);
}

void qsort(int **fechaCliCant,char **codProd,int ini,int fin){
    int limite=ini;
    if(ini>=fin) return;
    int med=(ini+fin)/2;
    cambiarInt(fechaCliCant[ini],fechaCliCant[med]);
    cambiarChar(codProd[ini],codProd[med]);
    for(int i=ini+1;i<=fin;i++){
        if(esMenor(fechaCliCant[i],fechaCliCant[ini])){
            limite++;
            cambiarInt(fechaCliCant[limite],fechaCliCant[i]);
            cambiarChar(codProd[limite],codProd[i]);
        }
    }
    cambiarInt(fechaCliCant[limite],fechaCliCant[ini]);
    cambiarChar(codProd[limite],codProd[ini]);
    qsort(fechaCliCant,codProd,ini,limite-1);
    qsort(fechaCliCant,codProd,limite+1,fin);
}

void cambiarInt(int *&dato1,int *&dato2){
    int *aux=dato1;
    dato1=dato2;
    dato2=aux;
}

void cambiarChar(char *&dato1,char *&dato2){
    char *aux=dato1;
    dato1=dato2;
    dato2=aux;
}

bool esMenor(int *datosI,int *datosIni){
    return datosI[0]<datosIni[0];
}

void leerDatos(ifstream &arch,int &fecha,int &dni,int &cant,char *&codigo){
    int dd,mm,aa;
    char car;
    codigo=leerCadena(arch);
    if(arch.eof()) return;
    arch>>dni>>car>>cant>>car>>dd>>car>>mm>>car>>aa;
    arch.get(); /*salto de linea*/
    fecha=aa*10000+mm*100+dd;
}

char *leerCadena(ifstream &arch){
    char cadena[60],*ptr;
    arch.getline(cadena,60,',');
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void aumentarCap(int **&fechaCliCant,char **&codigoProd,int &nd,int &cap){
    cap+=INCREMENTO;
    int **auxInt=new int*[cap]{};
    char **auxChar=new char*[cap]{};
    if(nd==0) nd=1;
    else{
        for(int i=0;i<nd;i++){
            auxInt[i]=fechaCliCant[i];
            auxChar[i]=codigoProd[i];
        }
        delete fechaCliCant;
        delete codigoProd;
    }
    fechaCliCant=auxInt;
    codigoProd=auxChar;
}

int *asignarInt(int fecha,int dni,int cant){
    int *registro=new int[3]{};
    registro[0]=fecha;
    registro[1]=dni;
    registro[2]=cant;
    return registro;
}

void pruebaDeCargaDePedidos(int **fechaCliCant,char **codProd,const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int *aux;
    arch<<"FECHA"<<setw(8)<<' '<<"DNI"<<setw(7)<<' '<<"CANTIDAD"<<setw(3)<<' '<<"CODIGO"<<endl;
    for(int i=0;fechaCliCant[i];i++){
        aux=fechaCliCant[i];
        imprimirFecha(arch,aux[0]);
        arch<<setw(3)<<' '<<aux[1]<<setw(7)<<aux[2]<<setw(5)<<' '<<codProd[i]<<endl;
    }
}

void imprimirFecha(ofstream &arch,int fecha){
    int dd,mm,aa;
    aa=fecha/10000;
    mm=(fecha/100)%100;
    dd=fecha%100;
    arch<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa<<setfill(' ');
}