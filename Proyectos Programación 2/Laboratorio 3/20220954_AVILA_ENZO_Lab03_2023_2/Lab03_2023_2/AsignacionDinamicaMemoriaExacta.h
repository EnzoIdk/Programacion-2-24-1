/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: Enzo
 *
 * Created on 17 de abril de 2024, 11:11 PM
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
        double *&precios);
void aumentarCap(char ***&productos,int *&stock,double *&precios,int &numDat,int &cap);
char **leerAuxProd(ifstream &arch);
char *leerCadena(ifstream &arch);
void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,
        int *stock,double *precios);
void lecturaDePedidos(const char *nombArch,int *&fechaPedidos,char ***&codigoPedidos,
        int ***&dniCantPedidos);
void aumentarCapFecha(int *&fechaPedidos,char ***&codPed,int ***&dniCant,
        int *&arrND,int *&arrCap,int &numDat,int &cap);
void insertarDatosDeFecha(int &numDatos,int &cap,int **&dniCant,char **&codPed,
        int dni,int cant,char *codProd);
void aumentarCapDatosFecha(int **&dniCant,char **&codPed,int &numDatos,int &cap);
int *insertarDniCant(int dni,int cant);
int leerDatosPed(ifstream &arch,int &dni,int &cant,int &fecha);
int buscarFecha(int *fechas,int dato,int numDat);
void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,
        char ***codigoPedidos,int ***dniCantPedidos);
void imprimirDatosPedidos(ofstream &arch,char **codPed,int **dniCant);
void reporteDeEnvioDePedidos(const char *nombArch,char ***productos,int *stock,
        double *precios,int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos);
void qSort(int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos,int izq,int der);
void cambiarF(int &dato1,int &dato2);
void cambiarC(char **&dato1,char **&dato2);
void cambiarD(int **&dato1,int **&dato2);
void imprimirDatosPedFecha(ofstream &arch,char ***productos,int *stock,double *precios,
        char **codPed,int **dniCant,double &ingresos,double &perdidas);
int buscarProd(char ***productos,char *codigo);
void imprimirFecha(ofstream &arch,int fecha);
void imprimirEncabezado(ofstream &arch);
void imprimirLinea(ofstream &arch,int longitud,char simbolo);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

