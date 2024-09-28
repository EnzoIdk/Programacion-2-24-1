/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: aml
 *
 * Created on 17 de abril de 2024, 09:15 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

#include "FuncionesVoid.h"
#include "funciones.h"


int main(int argc, char** argv) {
    int a[50]={10,15,2,82,35,44,17,91,32,12,20,5};
    int numDatos=12;
    
    qsort(a,numDatos,sizeof(int),intcmp);
    for(int i=0;i<numDatos;i++){
        cout<<setw(4)<<a[i];
    }
    cout<<endl;
//    
//    int nd;
//    char *nombres[100];
//    leerDatos(nombres,nd,"Personas.txt");
//    qsort(nombres,nd,sizeof(char*),cadcmp);
//    
//    cout<<endl;
    void *personal;
    int nd;
    leerDatos(personal,nd,"personal.csv");
    qsort(personal,nd,sizeof(void*),voidcmpNombre);
    qsort(personal,nd,sizeof(void*),voidcmpSueldo);
    imprimirDatos(personal,nd);
    return 0;
}

