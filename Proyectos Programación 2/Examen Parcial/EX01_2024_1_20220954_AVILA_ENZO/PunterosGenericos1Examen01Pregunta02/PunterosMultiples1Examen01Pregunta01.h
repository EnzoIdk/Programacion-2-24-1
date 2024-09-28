/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosMultiples1Examen01Pregunta01.h
 * Author: alulab14
 *
 * Created on 14 de mayo de 2024, 09:01 AM
 */

#ifndef PUNTEROSMULTIPLES1EXAMEN01PREGUNTA01_H
#define PUNTEROSMULTIPLES1EXAMEN01PREGUNTA01_H

void cargarVentas(char **&ventasLibroCodigo,int **&ventasDniFechaPuntaje,const char *nombArch);
void leerDatosVentas(ifstream &arch,char *&codigo,int &dni,int &fecha,int &puntaje);
char *leerCadena(ifstream &arch,char delim);
void aumentarCapVent(char **&arr1,int **&arr2,int &num,int &cap);
int *insertarInt(int dni,int fecha,int puntaje);
void pruebaDeCargaDeVentas(char **ventasLibroCodigo,int **ventasDniFechaPuntaje,const char *nombArch);
void cargaLibro(char ***&libro,const char *nombArch);
int charcmp(const void *a,const void *b);
char **leerDatosLib(ifstream &arch);
void aumentarCapLib(char ***&libro,int &num,int &cap);
void pruebaDeCargaDeLibros(char ***libro,const char *nombArch);

#endif /* PUNTEROSMULTIPLES1EXAMEN01PREGUNTA01_H */

