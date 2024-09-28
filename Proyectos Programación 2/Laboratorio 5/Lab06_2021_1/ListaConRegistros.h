/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConRegistros.h
 * Author: Enzo
 *
 * Created on 2 de mayo de 2024, 08:05 AM
 */

#ifndef LISTACONREGISTROS_H
#define LISTACONREGISTROS_H

void *leeregistro(ifstream &arch);
int cmpregistro(const void *reg1,const void *reg2);
void imprimeregistro(ofstream &arch,void *reg,void *&cabeceraFecha);
void buscarImprimirNombre(ofstream &arch,int licencia);
char *leerCadena(ifstream &arch);
void descomponerFecha(int fecha,int &dd,int &mm,int &aa);
void imprimirLinea(ofstream &arch,int longitud,char simbolo);

#endif /* LISTACONREGISTROS_H */

