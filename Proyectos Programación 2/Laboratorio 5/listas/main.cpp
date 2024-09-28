/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 1 de mayo de 2024, 14:32
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;
#include "funcionesGenericas.h"
#include "funcEnteros.h"
#include "funclista.h"
#include "listaDoble.h"
#include "funcCola.h"
/*
 * errores con los nombres de las funciones
 */
int main(int argc, char** argv) {

    ifstream arch("datos.txt", ios::in);
    if (not arch.is_open()){
        cout<<"error con la apertura del archivo: "<<endl;
        exit(1);
    }
    ofstream archImpr("impresion.txt", ios::out);
    if (not archImpr.is_open()){
        cout<<"error con la apertura del archivo: "<<endl;
        exit(1);
    }
    void*lista;
    construit(lista,leeEntero,arch,cosntruirDobleAtras);
    imprimir(lista, imprimEntero, archImpr);

    return 0;
}

