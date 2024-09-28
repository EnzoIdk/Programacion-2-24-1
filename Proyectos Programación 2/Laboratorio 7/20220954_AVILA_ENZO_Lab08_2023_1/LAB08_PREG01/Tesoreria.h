/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tesoreria.h
 * Author: Enzo
 *
 * Created on 28 de mayo de 2024, 11:51 PM
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"
class Tesoreria {
private:
    /*probando con arreglos dinámicos*/
//    class Presencial *lpresencial;
//    class Semipresencial *lsemipresencial;
//    class Virtual *lvirtual;
//    class Escala *lescala;
    class Presencial lpresencial[100];
    class Semipresencial lsemipresencial[100];
    class Virtual lvirtual[100];
    class Escala lescala[10];
public:
//    Tesoreria();
//    virtual ~Tesoreria();
//    void inicializarArreglos();
    void cargaescalas(const char*);
    void cargaalumnos(const char*);
    void actualiza(double);
    void imprime(const char*);
    void muestraEscala(int);
    void imprimeLinea(ofstream &,int,char);
};

#endif /* TESORERIA_H */

