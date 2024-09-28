/* 
 * File:   FlotaGenerica.cpp
 * Author: Lucas
 *
 * Created on 2 de mayo de 2024, 12:52
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>
#include <ratio>

#include "FlotaGenerica.h"

enum Pila{CABEZA, PESO};
enum Nodo{REGISTRO, SIGUIENTE};

void cargaCamiones(void * &flota, int numCamiones, double pesoMaximo, 
        void * (*leer)(ifstream &), double (*calcular)(void *), 
        const char * nombArch){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    void ** auxFlota=new void*[numCamiones]{}, ** pilaAux, * registro;
    double * pesoTotPila, pesoACargar, * pesoActualCamion;
    //INCIALIZAMOS
    for(int i=0; i<numCamiones; i++){
        pilaAux=new void*[2]{};
        pesoTotPila=new double;
        *pesoTotPila=0;
        //GUARDAMOS
        pilaAux[PESO]=pesoTotPila;
        auxFlota[i]=pilaAux;
    }
    //LEEMOS
    while(true){
        registro=leer(arch);
        if(arch.eof()) break;
        pesoACargar=calcular(registro);
        for(int i=0; i<numCamiones; i++){
            pilaAux=(void ** )auxFlota[i];
            pesoActualCamion=(double * )pilaAux[PESO];
            if(pesoACargar<=(pesoMaximo-(*pesoActualCamion))){
                push(auxFlota[i], registro);
                *pesoActualCamion+=pesoACargar;
                break;
            }
        }
    }
    flota=auxFlota;
}


void push(void * camion, void * dato){
    void ** pila=(void ** )camion;
    void ** nodo=new void*[2]{};
    nodo[REGISTRO]=dato;
    if(pilaVacia(camion)){
        pila[CABEZA]=nodo;
        nodo[SIGUIENTE]=nullptr;
    }
    else{
        nodo[SIGUIENTE]=pila[CABEZA];
        pila[CABEZA]=nodo;
    }
}

bool pilaVacia(void * pila){
    void ** auxPila=(void ** )pila;
    return auxPila[CABEZA]==nullptr;
}

void muestraCamiones(void * flota, int numCamiones, 
        void (*imprimir)(void * , ofstream &), const char * nombArch){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    void ** auxFlota=(void ** )flota;
    arch<<fixed<<setprecision(2);
    for(int i=0; i<numCamiones; i++){
        arch<<"Camion"<<setw(8)<<i+1<<":";
        imprimir(auxFlota[i], arch);
    }
}

