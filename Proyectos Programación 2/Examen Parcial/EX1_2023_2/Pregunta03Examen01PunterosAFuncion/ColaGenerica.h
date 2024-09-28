/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaGenerica.h
 * Author: Enzo
 *
 * Created on 8 de mayo de 2024, 02:02 PM
 */

#ifndef COLAGENERICA_H
#define COLAGENERICA_H

using namespace std;

void cargaEnteros(void *&cola,void*(*lee)(ifstream &),const char *nombArch);
void generacola(void *&cola);
void encola(void *&cola,void *dato);
void *desencola(void *&cola);
void crearNodo(void **&nuevoNodo,void *dato);
bool colavacia(void *cola);
void mostrarEnteros(void *cola,void (*imprime)(ofstream &,void*),const char *nombArch);

#endif /* COLAGENERICA_H */

