/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesVoid.h
 * Author: Enzo
 *
 * Created on 2 de mayo de 2024, 04:32 PM
 */

#ifndef FUNCIONESVOID_H
#define FUNCIONESVOID_H

void leerDatos(void *&pers,int &nd,const char *nombArch);
void *leerReg(ifstream &arch);
char *leerCad(ifstream &arch);
int voidcmpSueldo(const void *a,const void *b);
int voidcmpNombre(const void *a,const void *b);
void imprimirDatos(void *per,int nd);
void imprimirPersona(void *per);
#endif /* FUNCIONESVOID_H */

