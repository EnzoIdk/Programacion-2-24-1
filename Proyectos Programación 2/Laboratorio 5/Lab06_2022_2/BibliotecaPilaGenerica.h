/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaPilaGenerica.h
 * Author: Enzo
 *
 * Created on 2 de mayo de 2024, 10:12 PM
 */

#ifndef BIBLIOTECAPILAGENERICA_H
#define BIBLIOTECAPILAGENERICA_H

using namespace std;

void cargaarreglo(void *&arreglo,int (*cmp)(const void*,const void*),
        void *(*lee)(ifstream &),const char *nombArch);
void cargapila(void *&pila,void *arreglo);
void generapila(void *&pila);
void push(void *&pila,void *aux);
void *pop(void *&pila);
void muevepila(void *&pilaini,void *&pilafin);
void hanoi(int n,void *&pilaA,void *&pilaB,void *&pilaC);
bool pilavacia(void *pila);
void imprimepila(void *pila,void (*imprime)(ofstream &,void*),const char *nombArch);

#endif /* BIBLIOTECAPILAGENERICA_H */

