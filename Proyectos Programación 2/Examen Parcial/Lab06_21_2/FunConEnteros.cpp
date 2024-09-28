/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstdlib>
#include "BibGenerica.h"
#include "FunConEnteros.h"
#include "FunConRegistro.h"
using namespace std;


void *leenumero(ifstream &arch){
    int *num=new int;
    arch>>*num;
    if(arch.eof()) return nullptr;
    return num;
}

int prioridadnumero(void *dato){
    int *num=(int*)dato, prioridad;
    if(*num<50) prioridad=3;
    else if(*num>=50 and *num<=100) prioridad=2;
    else prioridad=1;
    return prioridad;
}

void muestranumero(ofstream &arch,void *dato,int i){
    int *num=(int*)dato;
    arch<<i<<' '<<*num<<endl;
}