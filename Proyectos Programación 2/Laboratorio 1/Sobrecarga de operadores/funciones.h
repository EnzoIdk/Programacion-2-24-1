/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: Enzo
 *
 * Created on 22 de marzo de 2024, 11:06 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void operator *=(struct Persona &p,double porcentaje);
//void operator <<(ostream &out,const struct Persona &p);
ostream & operator <<(ostream &out,const struct Persona &p);
void leerDatosExactos(int *&datos,int &numDatos);
void imprimirDatos(const int *datos,int numDatos);

#endif /* FUNCIONES_H */

