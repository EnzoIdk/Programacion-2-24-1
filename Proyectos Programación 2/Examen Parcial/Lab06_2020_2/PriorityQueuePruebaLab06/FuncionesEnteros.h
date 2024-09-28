/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesEnteros.h
 * Author: Enzo
 *
 * Created on 13 de mayo de 2024, 09:58 PM
 */

#ifndef FUNCIONESENTEROS_H
#define FUNCIONESENTEROS_H

void *leeRegInt(ifstream &arch);
int prioridadRegInt(void *reg);
void imprimeRegInt(ofstream &arch,void *reg);

#endif /* FUNCIONESENTEROS_H */

