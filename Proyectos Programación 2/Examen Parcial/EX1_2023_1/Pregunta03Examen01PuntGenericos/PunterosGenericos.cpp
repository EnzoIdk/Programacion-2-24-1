/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>       

using namespace std;

#include "PunterosGenericos.h"
#include "AperturaDeArchivos.h"
#define NO_ENCONTRADO -1

void CargaCursos(int *alumnos_cod,void *&alu,const char *nombArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    int numAlumnos,cod,pos;
    for(numAlumnos=0;alumnos_cod[numAlumnos];numAlumnos++);
    void *buffer[numAlumnos+1]{};
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get();
        pos=buscarAlu(alumnos_cod,cod);
        if(pos!=NO_ENCONTRADO){
            
        }
    }
}

int buscarAlu(int *arr,int dato){
    for(int i=0;arr[i];i++){
        if(arr[i]==dato) return i;
    }
    return NO_ENCONTRADO;
}