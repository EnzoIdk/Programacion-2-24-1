/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "PriorityQueu.h"
#include "FuncionesEnteros.h"

void *leeRegInt(ifstream &arch){
    void **registro=new void*[2]{};
    int *pri=new int,*num=new int;
    arch>>*pri;
    if(arch.eof()) return nullptr;
    arch>>*num;
    registro[0]=pri;
    registro[1]=num;
    return registro;
}

int prioridadRegInt(void *reg){
    void **registro=(void**)reg;
    int *prioridad=(int*)registro[0];
    return *prioridad;
}

void imprimeRegInt(ofstream &arch,void *reg){
    void **registro=(void**)reg;
    int *prioridad=(int*)registro[0],*numero=(int*)registro[1];
    arch<<'('<<*prioridad<<','<<*numero<<')'<<endl;
}