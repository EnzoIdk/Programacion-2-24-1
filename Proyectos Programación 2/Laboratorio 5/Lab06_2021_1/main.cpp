/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 2 de mayo de 2024, 08:04 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include <cstdlib>
#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistros.h"

using namespace std;

int main(int argc, char** argv) {
    void *lista1,*lista2;
//    void **aux,**cola;
//    int *dato;
    creaLista(lista1,leenum,cmpnum,"RegistroDeFaltas1.csv");
    creaLista(lista2,leenum,cmpnum,"RegistroDeFaltas2.csv");
//    aux=(void**)lista1;
//    cola=(void**)aux[1];
//    dato=(int*)cola[0];
//    cout<<*dato<<endl;
    imprimeLista(lista1,imprimenum,"Repnum.txt");
    imprimeLista(lista2,imprimenum,"Repnum2.txt");
    uneLista(lista1,lista2);
    imprimeLista(lista1,imprimenum,"Repnum3.txt");
//    aux=(void**)lista1;
//    cola=(void**)aux[1];
//    dato=(int*)cola[0];
//    cout<<*dato<<endl;
    creaLista(lista1,leeregistro,cmpregistro,"RegistroDeFaltas1.csv");
    creaLista(lista2,leeregistro,cmpregistro,"RegistroDeFaltas2.csv");
//    imprimeLista(lista1,imprimeregistro,"Repfalta1.txt");
    uneLista(lista1,lista2);
    imprimeLista(lista1,imprimeregistro,"Repfalta.txt");
    return 0;
}

