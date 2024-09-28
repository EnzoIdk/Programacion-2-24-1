/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "AperturaDeArchivos.h"
#include "PunteroVoid.h"
#include "PunterosMultiples1Examen01Pregunta01.h"
#define NO_ENCONTRADO -1

enum Venta{COD,TIT,AUT,VEND,SUMA,PROM,RANK};

void cargaventas(char ***libro,void *&ven){
    int num;
    for(num=0;libro[num];num++); /*memoria exacta*/
    void *bufferVen[num+1]{},*reg,**ventas;
    for(int i=0;libro[i];i++){
        reg=leerReg(libro[i]);
        bufferVen[i]=reg;
    }
    ventas=new void*[num+1]{};
    for(int i=0;i<num;i++) ventas[i]=bufferVen[i];
    ven=ventas;
}

void *leerReg(char **libro){
    void **registro=new void*[7]{};
    char *codigo,*nombre,*autor;
    int *cantVen=new int{0},*sumaPunt=new int{0},*ranking=new int{1};
    double *prom=new double{0};
    codigo=new char[strlen(libro[0])+1];
    strcpy(codigo,libro[0]);
    nombre=new char[strlen(libro[1])+1];
    strcpy(nombre,libro[1]);
    autor=new char[strlen(libro[2])+1];
    strcpy(autor,libro[2]);
    registro[COD]=codigo;
    registro[TIT]=nombre;
    registro[AUT]=autor;
    registro[VEND]=cantVen;
    registro[SUMA]=sumaPunt;
    registro[PROM]=prom;
    registro[RANK]=ranking;
    return registro;
}

void actualizaventas(int **ventasDniFechaPuntaje,char **ventasLibroCodigo,void *ven){
    void **ventas=(void**)ven;
    int *aux,puntaje;
    int posLibro;
    for(int i=0;ventasLibroCodigo[i];i++){
        posLibro=buscarLibro(ventasLibroCodigo[i],ven);
        if(posLibro!=NO_ENCONTRADO){
            aux=ventasDniFechaPuntaje[i];
            puntaje=aux[2];
            modificarventas(ventas[posLibro],puntaje);
        }
    }
}

int buscarLibro(char *codigo,void *ven){
    void **ventas=(void**)ven,**aux;
    char *codLibro;
    for(int i=0;ventas[i];i++){
        aux=(void**)ventas[i];
        codLibro=(char*)aux[COD];
        if(strcmp(codigo,codLibro)==0) return i;
    }
    return NO_ENCONTRADO;
}

void modificarventas(void *ven,int puntaje){
    void **ventas=(void**)ven;
    int *cantVen=(int*)ventas[VEND],*suma=(int*)ventas[SUMA],*ranking=(int*)ventas[RANK];
    double *promedio=(double*)ventas[PROM];
    (*cantVen)++;
    *suma+=puntaje;
    *promedio=(double)(*suma)/(*cantVen);
    if(*promedio>=30 and *promedio<70) *ranking=2;
    else if(*promedio>=70) *ranking=3;
}