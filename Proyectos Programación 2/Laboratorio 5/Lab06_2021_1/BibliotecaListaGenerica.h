/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: Enzo
 *
 * Created on 2 de mayo de 2024, 08:05 AM
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H

using namespace std; 

void creaLista(void *&lista,void* (*lee)(ifstream &),int (*cmp)(const void*,
        const void*),const char *nombArch);
void inicializarLista(void *&lista);
void insertar(void *dato,void *&lista,int (*cmp)(const void*,const void*));
void crearNuevoNodo(void **&nuevoNodo,void *dato);
void imprimeLista(void *lst,void (*imprime)(ofstream &,void*,void*&),const char *nombArch);
bool esListaVacia(void *lista);
void uneLista(void *&lista1,void *lista2);

#endif /* BIBLIOTECALISTAGENERICA_H */

