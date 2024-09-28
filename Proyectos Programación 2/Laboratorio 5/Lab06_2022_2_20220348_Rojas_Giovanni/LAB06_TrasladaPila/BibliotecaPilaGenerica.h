/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaPilaGenerica.h
 * Author: user
 *
 * Created on 2 de mayo de 2024, 16:57
 */

#ifndef BIBLIOTECAPILAGENERICA_H
#define BIBLIOTECAPILAGENERICA_H
#include <fstream>
using namespace std;

void abrirArchLeer(ifstream &arch,const char*nombArch);
void abrirArchEscribir(ofstream &arch,const char*nombArch);
void cargaarreglo(void*&arreglo,int(*cmp)(const void*,const void*),
        void*(*lee)(ifstream &),const char*nombArch);
void cargapila(void*&pilaini,void*arreglo);
void generapila(void*&pila);
void push(void*&pila,void*aux);
void muevepila(void*&pilaini,void*&pilafin);
void hanoi(int n,void*&pilaini,void*&pilaaux,void*&pilafin);
void*pop(void*&pilaini);
bool esPilaVacia(void*&pilaini);
void imprimepila(void*pilafin,void(*imprime)(ofstream &,void*),
        const char*nombArch);

#endif /* BIBLIOTECAPILAGENERICA_H */

