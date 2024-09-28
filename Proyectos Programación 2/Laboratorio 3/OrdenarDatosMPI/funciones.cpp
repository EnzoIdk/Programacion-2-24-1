/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "funciones.h"
#define INCREMENTO 5

void leerDatosPorIncremento(int *&datos,const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int dato,cap=0,numDat=0;
    datos=nullptr;
    while(true){
        arch>>dato;
        if(arch.eof()) break;
        if(numDat==cap) aumentarCap(datos,numDat,cap); /*solo se pasan los punteros y sus
                                                        numDat y cap para aumentar la capacidad*/
        datos[numDat-1]=dato;
        numDat++;
    }
}

void aumentarCap(int *&datos,int &numDat,int &cap){
    int *auxDatos;
    cap+=INCREMENTO;
    if(datos==nullptr){
        datos=new int[cap]{};
        numDat=1;
    }
    else{
        auxDatos=new int[cap]{};
        for(int i=0;i<numDat;i++) auxDatos[i]=datos[i];
        delete datos;
        datos=auxDatos;
    }
}

void ordenar(int *datos){
    int numDat=0;
    while(datos[numDat]) numDat++;
    qSort(datos,0,numDat-1);
}

void qSort(int *datos,int izq,int der){
    int limite,pos;
    if(izq>=der) return;
    pos=(izq+der)/2;
    cambiar(datos[izq],datos[pos]);
    limite=izq;
    for(int i=izq+1;i<=der;i++) {
        if(datos[i]<datos[izq]){
            limite++;
            cambiar(datos[limite],datos[i]);
        }            
    }
    cambiar(datos[limite],datos[izq]);
    qSort(datos,izq,limite-1);
    qSort(datos,limite+1,der);
}

void cambiar(int &dato1,int &dato2){
    int aux=dato1;
    dato1=dato2;
    dato2=aux;
}

void imprimir(int *datos){
    for(int i=0;datos[i];i++){
        cout<<datos[i]<<' ';
    }
}