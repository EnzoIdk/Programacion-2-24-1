/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Lucas
 * 
 * Created on 8 de julio de 2024, 07:56 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>

#include "Biblioteca.h"

#define MAXLIB 10
#define MAXLINEA 75

//CONSTRUCTOR, COPIA, DESTRUCTOR

Biblioteca::Biblioteca() {

}

Biblioteca::Biblioteca(const class Biblioteca &orig) {

}

Biblioteca::~Biblioteca() {

}

//GETTERS Y SETTERS

//METODOS
void Biblioteca::carga(const char * nombEst, const char * nombLib){
    ifstream archEst(nombEst, ios::in);
    if(not archEst.is_open()){
        cout<<"ERROR con archivo: "<<nombEst;
        exit(1);
    }
    ifstream archLib(nombLib, ios::in);
    if(not archLib.is_open()){
        cout<<"ERROR con archivo: "<<nombLib;
        exit(1);
    }
    this->cargarEstantes(archEst, archLib);
}

void Biblioteca::cargarEstantes(ifstream &archEst, ifstream &archLib){
    class Estante estTemp;
    //5,15
    while(true){
        estTemp.leer(archEst);
        if(archEst.eof()) break;
        //LLENAREMOS EL ESTANTE DE LIBROS (MAX 10)
        this->llenarEstantes(archLib, estTemp);
    }
}

void Biblioteca::llenarEstantes(ifstream &arch, class Estante &estante){
    class NLibro libTemp;
    class vector<NLibro> vTemp;
    double peso=0;
    //R,Educacion,48,0.2,10199403,2024,6
    for(int i=0; i<MAXLIB; i++){
        libTemp.leer(arch);
        if(arch.eof()) break;
        vTemp.push_back(libTemp);
        peso+=libTemp.GetPeso();
    }
    estante.actualizar(peso);
    mestantes[estante]=vTemp;
}

void Biblioteca::actualiza(int aa){
    for(auto &par:mestantes){
        for(class NLibro &lib:par.second) lib.actualiza(aa);
    }
}

void Biblioteca::muestra(const char * nomb){
    ofstream arch(nomb, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    arch<<fixed<<setprecision(1);
    //IMPRESION
    arch<<"Estantes:"<<endl;
    for(auto &par:mestantes){
        this->imprimirLinea(arch, '=');
        arch<<endl;
        par.first.imprimir(arch);
        arch<<"LIBROS EN EL ESTANTE:"<<endl;
        for(class NLibro &lib:par.second){
            arch<<endl;
            lib.imprimir(arch);
        }
    }
}

void Biblioteca::imprimirLinea(ofstream &arch, char car){
    for(int i=0; i<MAXLINEA; i++) arch<<car;
    arch<<endl;
}

void Biblioteca::prueba(double peso, const char * nomb){
    ofstream arch(nomb, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    arch<<fixed<<setprecision(1);
    //IMPRESION
    for(auto &par:mestantes){
        if(par.first.GetDisponible()>=peso){
            par.first.imprimir(arch);
            arch<<"LIBROS EN EL ESTANTE:"<<endl;
            for(class NLibro &lib:par.second){
                arch<<endl;
                lib.imprimir(arch);
            }    
        }
    }
}


