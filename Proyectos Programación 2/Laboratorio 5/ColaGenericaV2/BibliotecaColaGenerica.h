/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaColaGenerica.h
 * Author: Enzo
 *
 * Created on 3 de mayo de 2024, 12:30 AM
 */

#ifndef BIBLIOTECACOLAGENERICA_H
#define BIBLIOTECACOLAGENERICA_H

void crearCola(const char *nombArch,void *&cola,void*(*lee)(ifstream &));
void construirCola(void *&cola);
void inicializarCola(void *&cola);
void encolar(void *&cola,void *dato);
void *desencolar(void *&cola);
void crearNuevoNodo(void **&nuevoNodo,void *dato);
bool esColaVacia(void *cola);
void imprimirCola(void *cola,void (*imprime)(ofstream &,void*),const char *nombArch);

#endif /* BIBLIOTECACOLAGENERICA_H */

