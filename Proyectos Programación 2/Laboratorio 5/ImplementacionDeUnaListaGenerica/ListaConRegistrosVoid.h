/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConRegistrosVoid.h
 * Author: aml
 *
 * Created on 30 de abril de 2024, 08:33 AM
 */

#ifndef LISTACONREGISTROSVOID_H
#define LISTACONREGISTROSVOID_H

void *leeReg(ifstream &arch);
char *leerCadena(ifstream &arch);
int regCodcmp(const void *a,const void *b);
int regNombcmp(const void *a,const void *b);
int regSuelcmp(const void *a,const void *b);
void imprimeReg(void *reg);
void eliminaReg(void *reg);

#endif /* LISTACONREGISTROSVOID_H */

