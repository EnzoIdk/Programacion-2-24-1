/* 
 * File:   FuncionesRegistros.cpp
 * Author: Lucas
 *
 * Created on 7 de mayo de 2024, 17:34
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "FuncionesRegistros.h"

enum Registro{NUM, DNI, COD};

void * leeRegistro(ifstream &arch){
    void ** dato=new void*[3];
    int * num, numTemp, * dni, dniTemp;
    char * cod;
    //17,37751890,IMK4892
    arch>>numTemp;
    if(arch.eof()) return nullptr;
    arch.get();
    arch>>dniTemp;
    arch.get();
    cod=new char[8]{};
    arch.getline(cod, 8, '\n');
    //GUARDAMOS
    dni=new int;
    *dni=dniTemp;
    num=new int;
    *num=numTemp;
    dato[NUM]=num;
    dato[DNI]=dni;
    dato[COD]=cod;
    return dato;
}

void imprimeRegistro(ofstream &arch, void * dato){
    void ** auxDato=(void ** )dato;
    int * num=(int * )auxDato[NUM], * dni=(int * )auxDato[DNI];
    char * cod=(char * )auxDato[COD];
    //IMPRESION
    arch<<setw(3)<<*num<<setw(12)<<*dni<<setw(10)<<cod<<endl;
}

int cmpRegistro(const void * datoA, const void * datoB){
    void ** auxDatoA=(void ** )datoA, ** auxDatoB=(void ** )datoB;
    int * numA=(int * )auxDatoA[NUM], * numB=(int * )auxDatoB[NUM];
    return *numA-*numB;
}
