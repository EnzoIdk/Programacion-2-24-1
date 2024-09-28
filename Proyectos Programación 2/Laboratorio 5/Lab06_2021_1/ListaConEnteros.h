/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConEnteros.h
 * Author: Enzo
 *
 * Created on 2 de mayo de 2024, 08:05 AM
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

void *leenum(ifstream &arch);
int cmpnum(const void *dato1,const void *dato2);
void imprimenum(ofstream &arch,void *dato,void *&);

#endif /* LISTACONENTEROS_H */

