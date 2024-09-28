/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 22 de marzo de 2024, 11:05 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "Persona.h"
#include "funciones.h"

int main(int argc, char** argv) {
    struct Persona p1{43534,"Ana Perez",230.21};
    struct Persona p2{34534,"Juan Gomez",330.12};
    struct Persona p3{42584,"Maria Ruiz",430.21};
//    ifstream archPersonas("Personas.csv",ios::in);
//    if(not archPersonas.is_open()){
//        cout<<"ERROR: No se pudo abrir el archivo Personas.csv"<<endl;
//    }
//    cin>>p1;
    p1*=0.2;
    /*Esto se puede hacer con void operator << o con el ostream &operator <<*/
//    cout<<p1;
//    cout<<p2;
//    cout<<p3;
    cout<<p1<<p2<<p3; /*Esto solo se puede con el ostream &operator <<*/
    
//    int *datos,numDatos;
//    leerDatosExactos(datos,numDatos);
//    imprimirDatos(datos,numDatos);
    
    
    return 0;
}

