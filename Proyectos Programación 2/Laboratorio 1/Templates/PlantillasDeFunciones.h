/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PlantillasDeFunciones.h
 * Author: aml
 *
 * Created on 20 de marzo de 2024, 09:29 AM
 */

#ifndef PLANTILLASDEFUNCIONES_H
#define PLANTILLASDEFUNCIONES_H
#include <iostream>
#include <iomanip>
#include <fstream>
#define NO_ENCONTRADO -1

using namespace std;

/*template cuando no sabes que tipo de variable es*/
template <typename T>
/*T: tipo de dato de la variable a*/
void leerDatos(T *a,int &n,const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    n=0;
    while(true){
        arch>>a[n];
        if(arch.eof()) break;
        n++;
    }
}

template <typename T>
int buscar(int valorA,T *a,int n){
    for(int i=0;i<n;i++){
        if(valorA==a[i]) return i;
    }
    return NO_ENCONTRADO;
}

#endif /* PLANTILLASDEFUNCIONES_H */

