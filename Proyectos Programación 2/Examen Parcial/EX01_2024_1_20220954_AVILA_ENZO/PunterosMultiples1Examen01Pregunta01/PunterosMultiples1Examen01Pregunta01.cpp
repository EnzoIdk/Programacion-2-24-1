/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <cstring>

using namespace std;

#include "AperturaDeArchivos.h"
#include "PunterosMultiples1Examen01Pregunta01.h"
#define INCREMENTO 5

void cargarVentas(char **&ventasLibroCodigo,int **&ventasDniFechaPuntaje,const char *nombArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    int num=0,cap=0;
    char *codigo;
    int dni,fecha,puntaje;
    while(true){
        leerDatosVentas(arch,codigo,dni,fecha,puntaje);
        if(arch.eof()) break;
        if(num==cap) aumentarCapVent(ventasLibroCodigo,ventasDniFechaPuntaje,num,cap);
        ventasLibroCodigo[num-1]=codigo;
        ventasDniFechaPuntaje[num-1]=insertarInt(dni,fecha,puntaje);
        num++;
    }
}

void leerDatosVentas(ifstream &arch,char *&codigo,int &dni,int &fecha,int &puntaje){
    char car;
    int dd,mm,aa;
    codigo=leerCadena(arch,',');
    if(arch.eof()) return;
    arch>>dni>>car>>dd>>car>>mm>>car>>aa>>car>>puntaje;
    arch.get(); /*salto de linea*/
    fecha=aa*10000+mm*100+dd;
}

char *leerCadena(ifstream &arch,char delim){
    char cadena[60],*ptr;
    arch.getline(cadena,60,delim);
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void aumentarCapVent(char **&arr1,int **&arr2,int &num,int &cap){
    cap+=INCREMENTO;
    char **aux1=new char*[cap]{};
    int **aux2=new int*[cap]{};
    if(num==0) num=1;
    else{
        for(int i=0;i<num;i++){
            aux1[i]=arr1[i];
            aux2[i]=arr2[i];
        }
        delete arr1;
        delete arr2;
    }
    arr1=aux1;
    arr2=aux2;
}

int *insertarInt(int dni,int fecha,int puntaje){
    int *registro=new int[3]{};
    registro[0]=dni;
    registro[1]=fecha;
    registro[2]=puntaje;
    return registro;
}

void pruebaDeCargaDeVentas(char **ventasLibroCodigo,int **ventasDniFechaPuntaje,const char *nombArch){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
    int *auxInt;
    arch<<"CODIGO"<<setw(3)<<' '<<"DNI"<<setw(7)<<' '<<"FECHA"<<setw(5)<<' '<<"PUNTAJE"<<endl;
    for(int i=0;ventasDniFechaPuntaje[i];i++){
        auxInt=ventasDniFechaPuntaje[i];
        arch<<ventasLibroCodigo[i]<<setw(2)<<' '<<auxInt[0]<<setw(2)<<' '<<auxInt[1]<<setw(6)<<auxInt[2]<<endl;
    }
}

void cargaLibro(char ***&libro,const char *nombArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    int num=0,cap=0;
    char **registro;
    while(true){
        registro=leerDatosLib(arch);
        if(arch.eof()) break;
        if(num==cap) aumentarCapLib(libro,num,cap);
        libro[num-1]=registro;
        num++;
    }
    qsort(libro,num-1,sizeof(char***),charcmp);
}

int charcmp(const void *a,const void *b){
    void **regA=(void**)a,**regB=(void**)b;
    void **datoA=(void**)(*regA),**datoB=(void**)(*regB);
    char *tituloA=(char*)(datoA[1]),*tituloB=(char*)(datoB[1]);
    return strcmp(tituloA,tituloB);
}

char **leerDatosLib(ifstream &arch){
    char **registro=new char*[3]{};
    char *codigo,*nombre,*autor;
    codigo=leerCadena(arch,',');
    if(arch.eof()) return nullptr;
    nombre=leerCadena(arch,',');
    autor=leerCadena(arch,'\n');
    registro[0]=codigo;
    registro[1]=nombre;
    registro[2]=autor;
    return registro;
}

void aumentarCapLib(char ***&libro,int &num,int &cap){
    cap+=INCREMENTO;
    char ***aux=new char**[cap]{};
    if(num==0) num=1;
    else{
        for(int i=0;i<num;i++) aux[i]=libro[i];
        delete libro;
    }
    libro=aux;
}

void pruebaDeCargaDeLibros(char ***libro,const char *nombArch){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
    char **aux;
    arch<<"CODIGO"<<setw(9)<<' '<<"TITULO"<<setw(54)<<' '<<"AUTOR"<<endl;
    arch<<left;
    for(int i=0;libro[i];i++){
        aux=libro[i];
        arch<<setw(15)<<aux[0]<<setw(60)<<aux[1]<<setw(30)<<aux[2]<<endl;
    }
    arch<<right;
}