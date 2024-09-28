/* 
 * File:   ListaConEnteros.cpp
 * Author: Lucas
 *
 * Created on 3 de mayo de 2024, 0:03
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "ListaConEnteros.h"

enum Nodo{DATO, SIGUIENTE};

void * leeNum(ifstream &arch){
    void * registro;
    int dd, mes, aa, * fecha=new int;
    char bin;
    //35912665,O2Z-308,22/07/2019,156
    arch>>bin;
    if(arch.eof()) return nullptr;
    while(arch.get()!=','); //ELIMINAMOS EL DNI
    while(arch.get()!=','); //ELIMINAMOS EL CODIGO
    arch>>dd>>bin>>mes>>bin>>aa;
    while(arch.get()!='\n');
    //GUARDAMOS
    *fecha=(aa*10000+mes*100+dd);
    registro=fecha;
    return registro;
}

int cmpNum(const void * datoA, const void * datoB){
    void ** auxDatoA=(void ** )datoA, ** auxDatoB=(void ** )datoB;
    int * numA=(int * )auxDatoA, * numB=(int * )auxDatoB;
    return *numA-*numB;
}

void imprimeNum(ofstream &arch, void * dato){
    void ** auxDato=(void ** )dato;
    int * fecha=(int * )auxDato;
    arch<<*fecha<<endl;
}

