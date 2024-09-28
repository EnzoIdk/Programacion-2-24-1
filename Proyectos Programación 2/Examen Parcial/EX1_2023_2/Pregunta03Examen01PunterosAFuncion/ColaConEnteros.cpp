/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "ColaConEnteros.h"

using namespace std;

void *leenumero(ifstream &arch){
    int *num=new int;
    arch>>*num;
    if(arch.eof()) return nullptr;
    return num;
}

void imprimenumero(ofstream &arch,void *dato){
    int *num=(int*)dato;
    arch<<*num<<endl;
}