/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Primera.cpp
 * Author: Enzo
 * 
 * Created on 25 de junio de 2024, 04:39 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Primera.h"
#include "CursoAlumno.h"
Primera::Primera() {
    codacceso=nullptr;
}

Primera::Primera(const Primera& orig) {
}

Primera::~Primera() {
    if(codacceso!=nullptr) delete codacceso;
}

void Primera::SetCodacceso(const char *cad) {
    if(codacceso!=nullptr) delete codacceso;
    codacceso=new char[strlen(cad)+1];
    strcpy(codacceso,cad);
}

void Primera::GetCodacceso(char *cad) const {
    if(codacceso==nullptr) cad[0]=0;
    else strcpy(cad,codacceso);
}

void Primera::lee(ifstream& arch){
    CursoAlumno::lee(arch);
}

void Primera::muestra(){
    CursoAlumno::muestra();
}

void Primera::imprime(ofstream& arch){
    CursoAlumno::imprime(arch);
    char cad[10];
    GetCodcur(cad);
    arch<<setw(4)<<' '<<GetCiclo()<<cad<<endl;
}

void Primera::actualiza(){
    
}