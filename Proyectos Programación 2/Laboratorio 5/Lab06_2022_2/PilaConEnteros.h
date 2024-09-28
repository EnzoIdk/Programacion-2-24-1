/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PilaConEnteros.h
 * Author: Enzo
 *
 * Created on 2 de mayo de 2024, 10:12 PM
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H

void *leenumero(ifstream &arch);
int cmpnumero(const void *a,const void *b);
void imprimenumero(ofstream &arch,void *reg);

#endif /* PILACONENTEROS_H */

