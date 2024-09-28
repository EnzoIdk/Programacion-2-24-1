/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesEnteros.h
 * Author: Enzo
 *
 * Created on 13 de mayo de 2024, 07:53 PM
 */

#ifndef FUNCIONESENTEROS_H
#define FUNCIONESENTEROS_H

using namespace std;

void *leenum(ifstream &arch);
void imprimenum(ofstream &arch,void *dato);
int cmpnum(const void *a,const void *b);

#endif /* FUNCIONESENTEROS_H */

