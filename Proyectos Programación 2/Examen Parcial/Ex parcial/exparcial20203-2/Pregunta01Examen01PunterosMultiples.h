/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pregunta01Examen01PunterosMultiples.h
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 7 de mayo de 2024, 16:10
 */

#ifndef PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H
#define PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H

#include <fstream>
using namespace std;

void  cargarPedidos(int **&fechaClienteCantidad, char**&codigoDelProducto, const  char*nombarch);
int *obtenerPedido(ifstream &arch);
void  incrementarPed(int **&fechaClienteCantidad, char **&codigoDelProducto,int& ndPedi, int &capPedi);
void agregarEspacioProductos(char **&codigoDelProducto, int &ndProd, int &capProd);
char *lecturaExacta(ifstream &arch);
void pruebaDeCrargarDePedidos(int **fechaClientesCantidad, char **codigoDelPorducto,const char *nombarch);
void  imprimirMiniArregloPedidos(ofstream &arch,  int *datos, char *prod );
int cmpEnteros(const void *a, const void *b);
int cmpChars(const void*a, const void*b);
void   miQsort(int **&fechaClienteCantidad,char **&codigoDelProducto, int izq, int der) ;
void  cambiarInts(int *&fecha1, int *&fecha2);
void cambiarChars(char *&fecha1, char *&fecha2);
int compararEnteros(int *num1, int *num2);
#endif /* PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H */

