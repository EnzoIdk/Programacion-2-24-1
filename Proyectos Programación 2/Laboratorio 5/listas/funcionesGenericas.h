/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesGenericas.h
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 1 de mayo de 2024, 14:34
 */

#ifndef FUNCIONESGENERICAS_H
#define FUNCIONESGENERICAS_H

#include <fstream>
using namespace std;

void construit(void *&lista,void *(*leeEntero)(ifstream &arch), ifstream &arch, void (*construirLista)(void*, void*&) );
void imprimir(void *lista, void (*imprimEntero)(ofstream &arch, void*), ofstream &arch);
#endif /* FUNCIONESGENERICAS_H */

