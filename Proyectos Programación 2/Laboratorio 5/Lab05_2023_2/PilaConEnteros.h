/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PilaConEnteros.h
 * Author: Enzo
 *
 * Created on 1 de mayo de 2024, 09:22 AM
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H

void *leenumero(ifstream &arch);
double calculanumero(double pesoMax,void *dato);
int cmpnumero(const void *a,const void *b);
void imprimenumero(ofstream &arch,void *pila);


#endif /* PILACONENTEROS_H */

