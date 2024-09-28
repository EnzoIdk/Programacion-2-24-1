/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstdlib>

using namespace std;

#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistros.h"
enum Nodo{DATO,SGTE};
enum Lista{CABEZA,COLA};

void *leenum(ifstream &arch){
    int *fecha=new int;
    int lic,dd,mm,aa,inf;
    char cadena[8],car;
    arch>>lic;
    if(arch.eof()) return nullptr;
    arch.get();
    arch.getline(cadena,8,',');
    arch>>dd>>car>>mm>>car>>aa>>car>>inf;
    *fecha=aa*10000+mm*100+dd;
    return fecha;
}

int cmpnum(const void *dato1,const void *dato2){
    int *fecha1=(int*)dato1,*fecha2=(int*)dato2;
    return *fecha1-*fecha2;
}

void imprimenum(ofstream &arch,void *dato,void *&datoAnt){
    int *fecha=(int*)dato;
    arch<<*fecha<<endl;
}