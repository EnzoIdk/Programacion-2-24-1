/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void*leenumero(ifstream &arch){
    int*ptNum,num;
    arch>>num;
    if(arch.eof())return nullptr;
    ptNum = new int;
    *ptNum = num;
    return ptNum;
}

int cmpnumero(const void*a,const void*b){
    void **ai = (void**)a,**bi = (void**)b;
    void **regA=(void**)(*ai),**regB=(void**)(*bi);
    int*ptA=(int*)regA,*ptB=(int*)regB;
    return (*ptA) - (*ptB);
}

void imprimenumero(ofstream &arch,void*reg){
    int*num = (int*)reg;
    arch<<*num<<endl;
}