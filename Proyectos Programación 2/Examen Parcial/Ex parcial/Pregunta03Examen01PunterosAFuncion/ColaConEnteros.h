/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaConEnteros.h
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 7 de mayo de 2024, 19:07
 */

#ifndef COLACONENTEROS_H
#define COLACONENTEROS_H

#include <fstream>
using namespace std;

void   cargaEnteros(void *&cola, void* (*leenumero)(ifstream &arch),const char *nombarch);
void *leenumero(ifstream &arch);
void  mostrarEnteros(void *&cola, void(*imprimeNumero)(void*,ofstream &arch), const char*nombarch);
void imprimeNumero(void*recorrido, ofstream &arch);
#endif /* COLACONENTEROS_H */

