/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "AperturaDeArchivos.h"
#include "PunterosMultiples1Examen01Pregunta01.h"
#include "PunteroVoid.h"
#include "MuestraVoid.h"
#include "PunterosFuncion1Examen01Pregunta03.h"
#include "ColaPrioridadGenerica.h"
#include "Registros.h"

enum Reg{COD,TIT,AUT,RANK};

void *crearegistro(void *dato){
    void **registro=new void*[4]{};
    char *codigo,*titulo,*autor;
    int *ranking=new int;
    void **regDato=(void**)dato;
    char *codDato=(char*)regDato[COD],*titDato=(char*)regDato[TIT],*autDato=(char*)regDato[AUT];
    int *rankDato=(int*)regDato[6];
    codigo=new char[strlen(codDato)+1];
    strcpy(codigo,codDato);
    titulo=new char[strlen(titDato)+1];
    strcpy(titulo,titDato);
    autor=new char[strlen(autDato)+1];
    strcpy(autor,autDato);
    *ranking=*rankDato;
    registro[COD]=codigo;
    registro[TIT]=titulo;
    registro[AUT]=autor;
    registro[RANK]=ranking;
    return registro;
}

void imprimeregistro(ofstream &arch, void *dato){
    void **auxDato=(void**)dato;
    char *codigo=(char*)auxDato[COD],*titulo=(char*)auxDato[TIT],*autor=(char*)auxDato[AUT];
    int *ranking=(int*)auxDato[RANK];
    arch<<left<<setw(15)<<codigo<<setw(60)<<titulo<<setw(30)<<autor<<right<<
            setw(9)<<*ranking<<endl;
}