/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FlotaGenerica.h
 * Author: Enzo
 *
 * Created on 1 de mayo de 2024, 09:22 AM
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

void cargacamiones(void *&flota,int numcamiones,double pesomaximo,void *(*lee)(ifstream &),
        double (*calcula)(double,void*),const char *nombArch);
void push(void **&camiones,int &i,void *dato,double (*calcula)(double,void*),
        double pesomaximo,int numcamiones);
int pilavacia(void **pila);
void agregarDatoPila(void **&pila,void **nuevoNodo);
void muestracamiones(void *flota,int numcamiones,void(*imprime)(ofstream &,void*),
        const char *nombArch);


#endif /* FLOTAGENERICA_H */

