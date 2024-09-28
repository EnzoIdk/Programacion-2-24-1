/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "ListaConEnteros.h"

void *leeEnteros(ifstream &arch){
    int d,*dato;
    arch>>d;
    if(arch.eof()) return nullptr;
    dato=new int;
    *dato=d;
    return dato;
}

int intcmp(const void* a,const void* b){
    int *ai=(int*)a,*bi=(int*)b;
    return *ai-*bi;
}

void imprimeInt(void *a){
    int *ai=(int*)a;
    cout<<setw(6)<<*ai;
}

void eliminaInt(void *a){
    int *ai=(int*)a;
    delete ai;
}