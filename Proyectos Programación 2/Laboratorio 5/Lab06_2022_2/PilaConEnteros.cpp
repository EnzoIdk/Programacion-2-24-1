/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>  
#include <cstdlib>

using namespace std;

#include "PilaConEnteros.h"

void *leenumero(ifstream &arch){
    int *dato=new int,aux;
    arch>>aux;
    if(arch.eof()) return nullptr;
    *dato=aux;
    return dato;
}

int cmpnumero(const void *a,const void *b){
    void **ai=(void**)a,**bi=(void**)b;
    void **reg1=(void**)(*ai),**reg2=(void**)(*bi);
    int *dato1=(int*)reg1,*dato2=(int*)reg2;
    return *dato2-*dato1;
}

void imprimenumero(ofstream &arch,void *reg){
    int *num=(int*)reg;
    arch<<*num<<endl;
}