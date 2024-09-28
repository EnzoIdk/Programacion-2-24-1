/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PriorityQueu.h
 * Author: Enzo
 *
 * Created on 13 de mayo de 2024, 09:57 PM
 */

#ifndef PRIORITYQUEU_H
#define PRIORITYQUEU_H

void crearCola(void *&cola,void *(*lee)(ifstream &),int (*obtenerPrioridad)(void*),const char *nombArch);
void inicializarCola(void *&cola);
void encolar(void *&cola,void *dato,int (*obtenerPrioridad)(void*));
void agregar(void **ptActual,void **nuevoNodo,int (*obtenerPrioridad)(void*),
        void **ptAnt,void **cola,int p2);
void *desencolar(void *cola);
void crearNodo(void **&nodo,void *dato);
bool esColaVacia(void *cola);
void prueba(void *cola,void (*imprime)(ofstream &,void*),const char *nombArch);

#endif /* PRIORITYQUEU_H */

