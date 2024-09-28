/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: Enzo
 *
 * Created on 9 de abril de 2024, 07:27 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
        double *&precios);
char **leerDatosProd(ifstream &arch);
char *leerCadena(ifstream &arch);
void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,int *stock,
        double *precios);
void reporteProductos(ofstream &archReporte,char **productos,int stock,double precio);
void lecturaDePedidos(const char *nombArch,int *&fechaPedidos,char ***&codigoPedidos,
        int ***&dniCantPedidos);
void espaciosExactosCodPed(char **&codPed,char **&bufferCodPed,int nd);
void espaciosExactosDniCant(int **&dniCantPed,int **&bufferDniCant,int nd);
void colocarCodDni(int &numDatos,char **&bufferCodPedidos,char *codigo,int **&bufferDniCant,
        int dni,int cantidad);
void agregarDniCant(int *dniCant,int dni,int cantidad);
int buscarFecha(int fecha,int *buffer);
void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,char ***codigoPedidos,
        int ***dniCantPedidos);
void imprimirCodPedDni(ofstream &archReporte,char **codPed,int **dniCantPed);
void imprimirDatosFecha(ofstream &archReporte,char *codPed,int *dniCantPed);
void imprimirFecha(ofstream &archReporte,int fecha);
void imprimirLinea(ofstream &archReporte,int longitud,char simbolo);
void reporteDeEnvioDePedidos(const char *nombArch,char ***productos,int *stock,
        double *precios,int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos);
void imprimirDatosPedidos(ofstream &archReporte,char ***productos,int *stock,
        double *precios,char **codigoPedido,int **dniCant,double &totalIngresos,
        double &totalPerdido);
int buscarProducto(char ***productos,char *codPed);
int esProducto(char **producto,char *codPed);
void imprimirDatosPedidoProducto(ofstream &archReporte,char **producto,int &stock,
        double precio,char *codPedido,int *dniCant,double &totalIngresos,double &totalPerdido,int &nro);


#endif /* FUNCIONES_H */

