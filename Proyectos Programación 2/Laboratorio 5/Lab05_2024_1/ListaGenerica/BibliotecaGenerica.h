/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: Enzo
 *
 * Created on 13 de mayo de 2024, 07:53 PM
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

using namespace std;

void crealista(void *&lista,void *(*lee)(ifstream &),const char *nombArch);
void inicializarLista(void *&lista);
void insertalista(void *&lst,void *dato);
void *quitalista(void *&lista);
void crearNodo(void **&nuevoNodo,void *dato);
bool listavacia(void *lista);
void imprimelista(void *lista,void (*imprime)(ofstream &,void*),const char *nombArch);
void combinalista(void *ped1,void *ped2,void *&pedFin,int (*cmp)(const void*,const void*));

#endif /* BIBLIOTECAGENERICA_H */

