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

void *leenumero(ifstream &arch){
    double num,*numero=new double;
    arch>>num;
    if(arch.eof()) return nullptr;
    *numero=num;
    return numero;
}

double calculanumero(double pesoMax,void *dato){
    double *peso=(double*)dato;
    return pesoMax-*peso;
}

int cmpnumero(const void *dato1,const void *dato2){
    void **camion1=(void**)dato1,**camion2=(void**)dato2;
    void **pila1=(void**)camion1[DATO],**pila2=(void**)camion2[DATO];
    double *peso1=(double*)pila1[PESO],*peso2=(double*)pila2[PESO];
    return *peso2-*peso1;
}

void imprimenumero(ofstream &arch,void *pila){
    void **ant;
    double *dato;
    if(pila!=nullptr){
        ant=(void**)pila;
        dato=(double*)ant[DATO];
        imprimenumero(arch,ant[SGTE]);
        arch<<*dato<<endl;
    }
}