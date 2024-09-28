/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pregunta02Examen01PunterosGenericos.h
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 7 de mayo de 2024, 17:22
 */

#ifndef PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H
#define PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

void   cargarProductos(void *&prod, const char *nombarch);
void *obtenerProducto(ifstream &arch);
char *lecturaExacta(ifstream &arch);
void incrementarEspacio(void **&productos, int &cap, int &nd);
void pruebaDeCargaDeProductos(void *prod);
void impresionProd(void *prod, ofstream &arch);
int cmpVoid(const void*a, const void*b);
#endif /* PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H */

