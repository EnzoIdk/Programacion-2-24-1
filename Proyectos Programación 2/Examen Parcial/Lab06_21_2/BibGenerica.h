/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibGenerica.h
 * Author: Enzo
 *
 * Created on 14 de mayo de 2024, 12:16 AM
 */

#ifndef BIBGENERICA_H
#define BIBGENERICA_H

using namespace std;

void creacola(void *&cola,void *(*lee)(ifstream &),int (*prioridad)(void*),const char *nombArch);
void inicializarCola(void *&cola);
void encolar(void *&cl,void *dato,int (*prior)(void*));
void *desencolar(void *cl);
void crearNodo(void **&nuevoNodo,void *dato);
bool esColaVacia(void *cola);
void descargarcola(void *cola,void (*imprime)(ofstream &,void*,int),const char *nombArch);

#endif /* BIBGENERICA_H */

