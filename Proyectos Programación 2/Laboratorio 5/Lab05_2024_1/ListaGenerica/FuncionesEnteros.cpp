/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        


#include "BibliotecaGenerica.h"
#include "FuncionesEnteros.h"
using namespace std;

void *leenum(ifstream &arch){
    int *num=new int;
    arch>>*num;
    if(arch.eof()) return nullptr;
    return num;
}

void imprimenum(ofstream &arch,void *dato){
    int *num=(int*)dato;
    arch<<*num<<endl;
}

int cmpnum(const void *a,const void *b){
    int *ai=(int*)a,*bi=(int*)b;
    return *ai-*bi;
}