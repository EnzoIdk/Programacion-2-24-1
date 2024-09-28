/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tablero.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2024, 11:58 AM
 */

#include <fstream>
using namespace std;
#include <cstring>
#include "Tablero.h"
#include "A.h"
#include "B.h"
#include "C.h"

Tablero::Tablero() {
    numFichas=0;
}

Tablero::~Tablero() {
    for(int i=0;i<numFichas;i++) delete ficha[i];
}

void Tablero::leerFichas(ifstream &arch){
    char id[10],tipo;
    int fil,col;
    while(true){
        arch>>id;
        if(arch.eof()) break;
        arch>>tipo>>fil>>col;
        colocarFicha(id,tipo,fil,col);
    }
}

void Tablero::colocarFicha(char *id, char tipo, int fil, int col){
    switch(tipo){
        case 'A':
            ficha[numFichas]=new A;
            break;
        case 'B':
            ficha[numFichas]=new B;
            break;
        case 'C':
            ficha[numFichas]=new C;
            break;
    }
    //aún no aplicamos polimorfismo
    ficha[numFichas]->asigna(id,fil,col);
    numFichas++;
}

void Tablero::leerMovimientos(ifstream &arch){
    char id[10],dir;
    int cant;
    while(true){
        arch>>id;
        if(arch.eof()) break;
        arch>>dir>>cant;
        moverFicha(id,dir,cant);
    }
}

void Tablero::moverFicha(char *id, char dir, int cant){
    char idTab[10];
    for(int i=0;i<numFichas;i++){
        ficha[i]->GetId(idTab);
        if(strcmp(idTab,id)==0){
            //polimorfismo
            ficha[i]->mover(dir,cant);
            return;
        }
    }
}

void Tablero::imprimeDatos(ofstream &arch){
    for(int i=0;i<numFichas;i++){
        //polimorfismo
        ficha[i]->imprime(arch);
    }
}