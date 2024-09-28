/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 8 de abril de 2024, 17:33
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

#include <fstream>
using namespace std;

void lecturaProductos(const char *nombarch, char ***&productos,int *& stock, double *&precios);
void colocarProductos(ifstream &arch, char **&productos);
char *lecturaExacta(ifstream &arch);
void  pruebaDeLecturaDeProductos(const char *nombarch, char ***productos, int *stock, double *precios);
void imprimirProd(ofstream &arch, char**productos, int stock, double precio );
void lecturaDePedidos(const char *nombarch, int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos);
void colocarCodDni(char **&codigoPedidos,int &datos,int **&dniCantPedidos, char codigo[], int dni, int cant);
void colocarCantDni(int *dniCantPedidos,int dni, int cant);
int buscarFecha(int fecha, int bufferFechas[], int cant);
void gestarMemoriaCodPedidos(char **&bufferCodPed,char **&codigoPedidos, int nd);
void gestarMemoriaDniCant(int **&bufferDniCantPedidos,int **&dniCantPedidos, int nd);
void pruebaDeLecturaDePedidos(const char *nombarch, int *fechaPedidos, char ***codigoPedidos, 
        int ***dniCantPedidos);
void impresionFecha(int pedidos, ofstream &arch);
void impresionCodDniCant(char **codigoPedidos, int **dniCantPedidos, ofstream &arch);
void  impresionDniCant(int *dniCantPedidos, ofstream &arch, int num, char *codigoPedidos);
void reporteDeEnvioDePedidos(const char *nombarch, char ***productos,int *stock, double* precios,
        int* fechaPedidos,char ***codigoPedidos, int ***dniCantPedidos);
void impresionPedidos(ofstream &arch,char ***productos,char **codigoPedidos,int **dniCantPedidos,
        double *precios,int *stock,double &totalngresos,double&totalPerdida);
int buscarProd(char ***productos, char *codigoPedidos);
int condicionPro(char **productos, char codigoPedidos[]);
void imprimiProdCant(int *dniCantPedidos,char **productos, ofstream &arch, int &stock, double precios, int cont,
        double &totalIngresos, double &totalPerdida);
void linea(int cant, ofstream &arch, char simb);
#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

