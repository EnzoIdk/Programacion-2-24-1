/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesRegistro.h
 * Author: Enzo
 *
 * Created on 13 de mayo de 2024, 11:24 PM
 */

#ifndef FUNCIONESREGISTRO_H
#define FUNCIONESREGISTRO_H

void *leeRegistro(ifstream &arch);
int prioridadRegistro(void *dato);
void imprimeRegistro(ofstream &arch,void *);

#endif /* FUNCIONESREGISTRO_H */

