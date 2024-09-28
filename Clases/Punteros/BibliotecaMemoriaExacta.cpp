/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "BibliotecaMemoriaExacta.h"

void leerDatosExactos(int *&datos,int &numDat,const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int buffer[100];
    while(true){
        arch>>buffer[numDat];
        if(arch.eof()) break;
        numDat++;
    }
    datos=new int [numDat];
    for(int i=0;i<numDat;i++){
        datos[i]=buffer[i];
    }
}

void imprimirDatos(int *datos,int numDat){
    for(int i=0;i<numDat;i++){
        cout<<setw(4)<<datos[i]<<endl;
    }
}

void leerDatosExactos(int *&datos,const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int buffer[100];
    int numDatos=0;
    while(true){
        arch>>buffer[numDatos];
        if(arch.eof()) break;
        numDatos++;
    }
    datos=new int[numDatos+1]{}; /*todo se llena con ceros, con esto logramos que
                                  el último dato tmbn sea cero*/
    for(int i=0;i<numDatos;i++){
        datos[i]=buffer[i];
    }
}

void imprimirDatos(int *datos){
    /*esto te imprimiría todos los datos si ninguno de ellos es 0*/
    for(int i=0;datos[i];i++)
        cout<<setw(4)<<datos[i]<<endl;
}