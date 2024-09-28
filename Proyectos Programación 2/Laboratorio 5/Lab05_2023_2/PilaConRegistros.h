/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PilaConRegistros.h
 * Author: Enzo
 *
 * Created on 1 de mayo de 2024, 09:22 AM
 */

#ifndef PILACONREGISTROS_H
#define PILACONREGISTROS_H

void *leeregistro(ifstream &arch);
char *leerCadena(ifstream &arch);
double calcularegistro(double pesomax,void *dato);
int cmpregistro(const void *dato1,const void *dato2);
void imprimeregistro(ofstream &arch,void *pila);

#endif /* PILACONREGISTROS_H */

