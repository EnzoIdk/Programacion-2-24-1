/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

void* leeEntero(ifstream &arch){
    int dato, *dat=new int;
    arch>>dato;
    if (arch.eof()) return nullptr;
    *dat=dato;
    return dat;
}
void  imprimEntero(ofstream &arch, void *dato){
    int *num=(int*)dato;
    arch<<*num<<endl;
}