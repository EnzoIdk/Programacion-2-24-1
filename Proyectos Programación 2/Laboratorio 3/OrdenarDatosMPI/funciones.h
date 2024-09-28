/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: aml
 *
 * Created on 16 de abril de 2024, 08:45 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void leerDatosPorIncremento(int *&datos,const char *nombArch);
void aumentarCap(int *&datos,int &numDat,int &cap);
void ordenar(int *datos);
void qSort(int *datos,int izq,int der);
void cambiar(int &,int &);
void imprimir(int *);

#endif /* FUNCIONES_H */

