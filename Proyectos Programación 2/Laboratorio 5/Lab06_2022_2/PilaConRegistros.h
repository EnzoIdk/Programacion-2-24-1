/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PilaConRegistros.h
 * Author: Enzo
 *
 * Created on 2 de mayo de 2024, 10:12 PM
 */

#ifndef PILACONREGISTROS_H
#define PILACONREGISTROS_H

void *leeregistro(ifstream &arch);
char *leerCadena(ifstream &arch);
int cmpregistro(const void *a,const void *b);
void imprimeregistro(ofstream &arch,void *reg);

#endif /* PILACONREGISTROS_H */

