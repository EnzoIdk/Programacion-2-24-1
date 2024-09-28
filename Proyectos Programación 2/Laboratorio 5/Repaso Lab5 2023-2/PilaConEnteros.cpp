/* 
 * File:   PilaConEnteros.cpp
 * Author: Lucas
 *
 * Created on 2 de mayo de 2024, 12:52
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "PilaConEnteros.h"

enum Pila{CABEZA, PESO};
enum Nodo{REGISTRO, SIGUIENTE};

void * leeNumero(ifstream &arch){
    //9
    void * registro;
    double * num=new double, numTemp;
    arch>>numTemp;
    if(arch.eof()) return nullptr;
    *num=numTemp;
    //GUARDAMOS
    registro=num;
    return registro;
}

double calculaNumero(void * registro){
    double * peso=(double * )registro;
    return *peso;
}

int cmpNumero(const void * regA, const void * regB){
    void ** pilaA=(void ** )regA, ** pilaB=(void ** )regB;
    void ** auxA=(void ** )(*pilaA), ** auxB=(void ** )(*pilaB);
    double * pesoA=(double * )auxA[PESO], * pesoB=(double * )auxB[PESO];
    return *pesoB-*pesoA;
}

void imprimeNumero(void * camion, ofstream &arch){
    void ** pila=(void ** )camion;
    double * pesoTotal=(double * )pila[PESO], * pesoAux;
    void ** recorre=(void ** )pila[CABEZA], ** dato;
    arch<<"Peso:"<<setw(10)<<*pesoTotal<<endl;
    while(recorre){
        dato=(void ** )recorre[REGISTRO];
        pesoAux=(double * )(dato);
        arch<<*pesoAux<<endl;
        recorre=(void ** )recorre[SIGUIENTE];
    }
}
