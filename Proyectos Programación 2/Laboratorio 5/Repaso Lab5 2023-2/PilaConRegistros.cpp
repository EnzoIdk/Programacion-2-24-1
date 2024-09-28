/* 
 * File:   PilaConRegistros.cpp
 * Author: Lucas
 *
 * Created on 2 de mayo de 2024, 12:52
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "PilaConRegistros.h"

enum Pila{CABEZA, PESO_TOT};
enum Registro{COD, DNI, PESO};
enum Nodo{REGISTRO, SIGUIENTE};

void * leeRegistro(ifstream &arch){
    void ** registro=new void*[3]{};
    //ICX-503,27912250,1,50
    char * cod=new char[8]{};
    int * dni=new int, cantidad;
    double * pesoTotal=new double, peso;
    //LECTURA
    arch.getline(cod, 8, ',');
    if(arch.eof()) return nullptr;
    arch>>*dni;
    arch.get(); //,
    arch>>cantidad;
    arch.get(); //,
    arch>>peso;
    arch.get(); //\n
    //GUARDAMOS
    *pesoTotal=peso*cantidad;
    registro[COD]=cod;
    registro[DNI]=dni;
    registro[PESO]=pesoTotal;
    return registro;
}

double calculaRegistro(void * registro){
    void ** datos=(void ** )registro;
    double * peso=(double * )datos[PESO];
    return *peso;
}

int cmpRegistro(const void * datoA, const void * datoB){
    void ** auxDatoA=(void ** )datoA, ** auxDatoB=(void ** )datoB;
    void ** pilaA=(void ** )(*auxDatoA), ** pilaB=(void ** )(*auxDatoB);
    double * pesoA=(double * )pilaA[PESO_TOT], 
            * pesoB=(double * )pilaB[PESO_TOT];
    return (*pesoB-*pesoA)*1000;
}

void imprimeRegistro(void * camion, ofstream &arch){
    void ** auxCamion=(void ** )camion;
    double * pesoTotal=(double * )auxCamion[PESO_TOT];
    arch<<"Peso:"<<setw(10)<<*pesoTotal<<endl;
    arch<<"Lista de pedidos:"<<endl;
    imprimePilaRegistro(auxCamion[CABEZA], arch);
    arch<<endl;
}

void imprimePilaRegistro(void * cabeza, ofstream &arch){
    void ** datos, ** recorre=(void ** )cabeza;
    int * dni;
    double * peso;
    char * cod;
    while(recorre){
        datos=(void ** )recorre[REGISTRO];
        dni=(int * )datos[DNI];
        cod=(char * )datos[COD];
        peso=(double * )datos[PESO];
        arch<<setw(18)<<cod<<setw(10)<<*dni<<setw(10)<<*peso<<endl;
        recorre=(void ** )recorre[SIGUIENTE];
    }
}



