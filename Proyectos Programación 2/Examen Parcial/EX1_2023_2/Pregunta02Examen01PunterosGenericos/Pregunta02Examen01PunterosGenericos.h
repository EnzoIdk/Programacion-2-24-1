/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pregunta02Examen01PunterosGenericos.h
 * Author: Enzo
 *
 * Created on 8 de mayo de 2024, 09:33 AM
 */

#ifndef PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H
#define PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H

using namespace std;

void cargarProductos(void *&prod,const char *nombArch);
int voidcmpCod(const void *a,const void *b);
void *leerRegProd(ifstream &arch);
void *leerRegDatos(ifstream &arch);
char *leerCadenaExacta(ifstream &arch);
void aumentarCap(void **&productos,int &numDat,int &cap);
void pruebaDeCargaDeProductos(void *prod);
void imprimirDatosProductos(ofstream &arch,void *dat);

#endif /* PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H */

