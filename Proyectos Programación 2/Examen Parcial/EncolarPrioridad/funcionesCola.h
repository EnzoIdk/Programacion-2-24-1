/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesCola.h
 * Author: Enzo
 *
 * Created on 12 de mayo de 2024, 08:25 PM
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H

void construirCola(void *&cola);
void encolar(void *cola,char categoria,int dni);
bool esColaVacia(void *cola);
void **crearNodo(char categoria,int dni);
void imprimirCola(void *cola);
void imprime(void *datoCat,void *datoDNI);

#endif /* FUNCIONESCOLA_H */

