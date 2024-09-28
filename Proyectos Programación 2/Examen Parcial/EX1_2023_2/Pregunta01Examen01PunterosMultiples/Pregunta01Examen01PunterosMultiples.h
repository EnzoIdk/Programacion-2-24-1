/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pregunta01Examen01PunterosMultiples.h
 * Author: Enzo
 *
 * Created on 8 de mayo de 2024, 09:04 AM
 */

#ifndef PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H
#define PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H

using namespace std;

void cargarPedidos(int **&fechaCliCant,char **&codigoProd,const char *nombArch);
void qsort(int **fechaCliCant,char **codProd,int ini,int fin);
void cambiarInt(int *&dato1,int *&dato2);
void cambiarChar(char *&dato1,char *&dato2);
bool esMenor(int *datosI,int *datosIni);
void leerDatos(ifstream &arch,int &fecha,int &dni,int &cant,char *&codigo);
char *leerCadena(ifstream &arch);
void aumentarCap(int **&fechaCliCant,char **&codigoProd,int &nd,int &cap);
int *asignarInt(int fecha,int dni,int cant);
void pruebaDeCargaDePedidos(int **fechaCliCant,char **codProd,const char *nombArch);
void imprimirFecha(ofstream &arch,int fecha);

#endif /* PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H */

