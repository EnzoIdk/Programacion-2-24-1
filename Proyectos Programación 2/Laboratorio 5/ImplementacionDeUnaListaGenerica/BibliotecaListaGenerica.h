/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: aml
 *
 * Created on 30 de abril de 2024, 08:32 AM
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H

void crearLista(const char *nombArch,void *&lista,void* (*lee)(ifstream &),
        int (*cmp)(const void*,const void*));
void insertar(void *dato,void *&lista,int(*cmp)(const void*,const void*));
void imprimirLista(void *lst,void (*imprime)(void*));
void eliminarLista(void *lst,void  (*elimina)(void*));

#endif /* BIBLIOTECALISTAGENERICA_H */

