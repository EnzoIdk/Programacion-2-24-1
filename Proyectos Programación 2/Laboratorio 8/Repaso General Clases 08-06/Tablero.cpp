/* 
 * File:   Tablero.cpp
 * Author: Lucas
 * 
 * Created on 9 de junio de 2024, 12:46
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>

#include "Tablero.h"
#include "A.h"
#include "B.h"
#include "C.h"

//CONSTRUCTOR, COPIA, DESTRUCTOR
Tablero::Tablero() {
    
}

Tablero::Tablero(const class Tablero &orig) {
}

Tablero::~Tablero() {
    
}

//GETTERS Y SETTERS

//METODOS
void Tablero::leerFichas(const char * nomb){
    ifstream arch(nomb, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    char id[5], tipo;
    int fila, columna;
    //F3	C	6	9
    while(true){
        arch.getline(id, 5, ' ');
        if(arch.eof()) break;
        arch>>tipo>>fila>>columna;
        arch.get(); //\n
        //ASIGNAMOS
        this->colocarFicha(id, tipo, fila, columna);
    }
}

void Tablero::colocarFicha(char * id, char tipo, int fila, int columna){
    class Ficha * ficha;
    //SELECTIVA
    switch(tipo){
        case 'A':
            ficha=new class A;
            break;
        case 'B':
            ficha=new class B;
            break;
        case 'C':
            ficha=new class C;
            break;
    }
    //ASIGNACION
    ficha->asignar(id, fila, columna);
    lista.insertar(ficha); //PASAMOS LA DM DE ficha PARA INSERTAR EN LA LISTA
}

void Tablero::leerMovimientos(const char *nomb){
    ifstream arch(nomb, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    char id[5], dir;
    int esp;
    //F2  S	2
    while(true){
        arch.getline(id, 5, ' ');
        if(arch.eof()) break;
        arch>>dir>>esp;
        arch.get(); //\n
        lista.moverFicha(id, dir, esp);
    }
}

void Tablero::imprimirFichas(const char * nomb){
    ofstream arch(nomb, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    lista.imprimir(arch);
}


//FUNCIONES
