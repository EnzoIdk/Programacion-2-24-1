/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "BibliotecaColaGenerica.h"
#include "ColaConEnteros.h"

void *leeEntero(ifstream &arch){
    int *ptNum=new int,num;
    arch>>num;
    if(arch.eof()) return nullptr;
    *ptNum=num;
    return ptNum;
}

void imprimeInt(ofstream &arch,void *reg){
    int *num=(int*)reg;
    arch<<*num<<endl;
}