/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "PilaConEnteros.h"
#include "PilaConRegistros.h"
#include "FlotaGenerica.h"

enum Pila{INICIO,PESO};
enum Camion{DATO,SGTE};

void cargacamiones(void *&flota,int numcamiones,double pesomaximo,void* (*lee)(ifstream &),
        double(*calcula)(double,void*),const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **camiones=new void*[numcamiones+1]{},**pila;
    double *peso;
    /*inicializando las pilas*/
    for(int i=0;i<numcamiones;i++){
        pila=new void*[2]{};
        pila[INICIO]=nullptr;
        peso=new double{0};
        pila[PESO]=peso;
        camiones[i]=pila;
    }
    void *dato;
    int i=0;
    while(true){
        dato=lee(arch);
        if(arch.eof()) break;
        if(i<numcamiones) push(camiones,i,dato,calcula,pesomaximo,numcamiones);
    }
    flota=camiones;
}

void push(void **&camiones,int &i,void *dato,double (*calcula)(double,void*),
        double pesomaximo,int numcamiones){
    void *aux=(void**)camiones[i];
    void **pila=(void**)aux;
    void **nuevoNodo=new void*[2]{};
    nuevoNodo[DATO]=dato;
    nuevoNodo[SGTE]=nullptr;
    if(pilavacia(pila)) pila[INICIO]=nuevoNodo;
    else{
        double peso=pesomaximo-calcula(pesomaximo,dato);
        double *pesoAnterior=(double*)pila[PESO];
        if(*pesoAnterior+peso<=pesomaximo) agregarDatoPila(pila,nuevoNodo);
        else{
            i++; /*a la pila siguiente*/
            if(i==numcamiones) return;
            else{
                /*agrego pila*/
                aux=(void**)camiones[i];
                pila=(void**)aux;
                agregarDatoPila(pila,nuevoNodo);
            }
        }
    }
    double valor=pesomaximo-calcula(pesomaximo,dato);
    double *pesoAnt=(double*)pila[PESO];
    double *pesoPtr=new double{valor+*pesoAnt};
    delete pesoAnt;
    pila[PESO]=pesoPtr;
}

int pilavacia(void **pila){
    return pila[INICIO]==nullptr;
}

void agregarDatoPila(void **&pila,void **nuevoNodo){
    void **aux=(void**)pila[INICIO];
    void **ant=nullptr;
    while(aux){
        ant=aux;
        aux=(void**)aux[SGTE]; /*se busca hasta el último dato*/
    }
    if(ant==nullptr) pila[INICIO]=nuevoNodo;
    else ant[SGTE]=nuevoNodo;
}

void muestracamiones(void *flota,int numcamiones,void(*imprime)(ofstream &,void*),
        const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<setprecision(2)<<fixed;
    void **camiones=(void**)flota;
    void **pila;
    double *peso;
    for(int i=0;i<numcamiones;i++){
        pila=(void**)camiones[i];
        peso=(double*)pila[PESO];
        arch<<"Camion "<<i+1<<": PESO:  "<<*peso<<endl;
        imprime(arch,pila[INICIO]);
    }
}