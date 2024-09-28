/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 20 de marzo de 2024, 08:18 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Persona.h"
#include "funciones.h"

/*Lab 1 hasta operadores sobrecargados y bibliotecas estáticas*/

int main(int argc, char** argv) {
    struct Persona p(1234,"Ana Perez",2.2);
//    struct Persona p2(12453,"Juan Gomez",5733.12);
//    struct Persona p3(12929,"Maria Ruiz",4733.12);
//    ifstream arch("personas.csv",ios::in);
//    if(not arch.is_open()){
//        cout<<"ERROR: No se pudo abrir el archivo personas.csv"<<endl;
//        exit(1);
//    }
//    struct Persona empleados[100];
//    int n=0;
//    while(true){
//        arch>>empleados[n];
//        if(arch.eof()) break;
//        n++;
//    }
//    for(int i=0;i<n;i++){
//        cout<<empleados[i];
//    }
    
    
    p*=0.2;
    cout<<p<<endl;
    
    return 0;
}

