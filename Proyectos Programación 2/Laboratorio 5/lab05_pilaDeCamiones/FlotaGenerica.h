/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FlotaGenerica.h
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 30 de abril de 2024, 7:09
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

#include <fstream>
using namespace std;

void cargacamiones(void *&flota, int numcamiones, int pesomaximo, void*(*leenumero)(ifstream &arch), 
       int(*calculanumero)(void*),ifstream &arch);
int calculanumero(void *numero);
void push(void *&pila, void *numero);
void muestracamiones(void *flota,int numcamiones, int pesomaximo,void(*imprimenumero)(ofstream &arch,void*),
        ofstream &arch);
void   ingresarAPila(ofstream &arch, int ind,void *camion, void(*imprimenumero)(ofstream &arch,void*));
void asiganarMax(int num,void *camion );
#endif /* FLOTAGENERICA_H */

