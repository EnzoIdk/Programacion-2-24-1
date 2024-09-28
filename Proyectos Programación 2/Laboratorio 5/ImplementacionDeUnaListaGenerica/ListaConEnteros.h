/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConEnteros.h
 * Author: aml
 *
 * Created on 30 de abril de 2024, 08:32 AM
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

void *leeEnteros(ifstream &arch);
int intcmp(const void* a,const void* b);
void imprimeInt(void *a);
void eliminaInt(void *a);

#endif /* LISTACONENTEROS_H */

