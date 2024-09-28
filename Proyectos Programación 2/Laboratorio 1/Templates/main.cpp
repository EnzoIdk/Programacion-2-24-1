/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: aml
 *
 * Created on 20 de marzo de 2024, 09:11 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Persona.h"
#include "PlantillasDeFunciones.h"
/*nosotros nos adaptamos a la estructura de la plantilla*/
#include "FunCPersona.h"
#define NO_ENCONTRADO -1


int main(int argc, char** argv) {
    int a[30],nA,posA,valorA=73;
    leerDatos(a,nA,"Datos.txt");
    posA=buscar(valorA,a,nA);
    if(posA!=NO_ENCONTRADO){
        cout<<"Buscando el dato: "<<endl;
        cout<<"Pos = "<<posA<<endl;
        cout<<"a["<<posA<<"]= "<<a[posA]<<endl;
    }
    
    struct Persona persona[100];
    int nP,posP,dniP=85002317;
    leerDatos(persona,nP,"personas.csv");
    posP=buscar(dniP,persona,nP);
    if(posP!=NO_ENCONTRADO){
        cout<<"Buscando a la persona: "<<endl;
        cout<<"Pos = "<<posP<<endl;
        cout<<"a["<<posP<<"]= "<<persona[posP];
    }
    return 0;
}

