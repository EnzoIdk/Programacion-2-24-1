/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "ListaConCadenas.h"

void *leeCad(ifstream &arch){
    char cad[60],*ptr;
    arch.getline(cad,60);
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cad)+1];
    strcpy(ptr,cad);
    return ptr;
}

int cadcmp(const void *a,const void *b){
    char *ai=(char*)a,*bi=(char*)b;
    return strcmp(ai,bi);
}

void imprimeCad(void *cad){
    char *cadena=(char*)cad;
    cout<<cadena<<endl;
}

void eliminaCad(void *cad){
    char *cadena=(char*)cad;
    delete cadena;
}