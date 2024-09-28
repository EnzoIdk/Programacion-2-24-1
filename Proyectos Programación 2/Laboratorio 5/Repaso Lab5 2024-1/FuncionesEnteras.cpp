/* 
 * File:   FuncionesEnteras.cpp
 * Author: Lucas
 *
 * Created on 7 de mayo de 2024, 17:34
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "FuncionesEnteras.h"

void * leeNum(ifstream &arch){
    void * dato;
    int * num, numTemp;
    //LEER
    arch>>numTemp;
    if(arch.eof()) return nullptr;
    num=new int;
    *num=numTemp;
    dato=num;
    return dato;
}

void imprimeNum(ofstream &arch, void * dato){
    void ** auxDato=(void ** )dato;
    int * num=(int * )auxDato;
    arch<<*num<<endl;
}

int cmpNum(const void * datoA, const void * datoB){
    void ** auxDatoA=(void ** )datoA, ** auxDatoB=(void ** )datoB;
    int * numA=(int * )auxDatoA, * numB=(int * )auxDatoB;
    return *numA-*numB;
}
