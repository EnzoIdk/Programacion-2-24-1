/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "AperturaDeArchivos.h"
#include "PunterosMultiples1Examen01Pregunta01.h"
#include "PunteroVoid.h"
#include "MuestraVoid.h"
#include "PunterosFuncion1Examen01Pregunta03.h"
#include "ColaPrioridadGenerica.h"
#include "Registros.h"

enum Cola{INI,FIN3,FIN2,FIN1};
enum Nodo{DATO,SGTE};
void cargarranking(void *&rank,void *(*crea)(void*),void *ven){
    void **ventas=(void**)ven;
    void *dato;
    generacola(rank);
    for(int i=0;ventas[i];i++){
        dato=crea(ventas[i]);
        encola(rank,dato);
    }
}

void muestraranking(void *rank,void (*imprime)(ofstream &,void*),const char *nombArch,void *ven){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **auxRank=(void**)rank;
    void **ini=(void**)auxRank[INI];
    void *dato;
    arch<<"CODIGO"<<setw(9)<<' '<<"TITULO"<<setw(54)<<' '<<"AUTOR"<<setw(30)<<
            ' '<<"RANKING"<<endl;
    while(!colavacia(rank)){
        dato=desencola(rank);
        imprime(arch,dato);
    }
}