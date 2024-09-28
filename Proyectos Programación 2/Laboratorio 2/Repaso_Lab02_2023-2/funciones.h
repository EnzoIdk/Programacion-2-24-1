/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: Enzo
 *
 * Created on 11 de abril de 2024, 10:34 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
        double *&precios);
void llenarPunteros(char ***&productos,int *&stock,double *&precios,
        double *bufferPrecios,char ***bufferProductos,int *bufferStock,int numDatos);
char **leerProductos(ifstream &arch);
char *leerCadena(ifstream &arch);
void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,int *stock,
        double *precios);
void imprimirProductos(ofstream &arch,char **productos,int stock,double precio);
void lecturaDePedidos(const char *nombArch,int *&fechaPedidos,char ***&codigoPedidos,
        int ***&dniCantPedidos);
void llenarPunterosPedidos(int *&fechaPedidos,char ***&codigoPedidos,int ***&dniCantPedidos,
        int *bufferFechas,char ***bufferCodPed,int ***bufferDniCantPed,int *nd,int numDatos);
void espacioExactoCodPed(char **&codigoPedido,char **&bufferCodPed,int nd);
void espacioExactoDniCant(int **&dniCant,int **&bufferDniCant,int nd);
void agregarDatos(int **&bufferDniCantPed,char **&bufferCodPed,int dni,int cant,
        char *codigo,int &nd);
void agregarDniCantPed(int *dniCantPed,int dni,int cant);
int buscarFecha(int *fechas,int fecha);
void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,char ***codigoPedidos,
        int ***dniCantPedidos);
void imprimirDatosFecha(ofstream &arch,char **codPedidos,int **dniCantPedidos);
void imprimirCodDniCant(ofstream &arch,char *codPedido,int *dniCant);
void imprimirFecha(ofstream &arch,int fecha);
void reporteDeEnvioDePedidos(const char *nombArch,char ***productos,int *stock,
        double *precios,int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos);
void imprimirDatosPedidos(ofstream &archReporte,char ***productos,int *stock,
        double *precios,char **codigoPedido,int **dniCant,double &totalIngresos,
        double &totalPerdido);
int buscarProducto(char ***productos,char *codPed);
int esProducto(char **producto,char *codPed);
void imprimirLinea(ofstream &arch,int longitud,char simbolo);
void imprimirDatosPedidoProducto(ofstream &archReporte,char **producto,int &stock,
        double precio,char *codPedido,int *dniCant,double &totalIngresos,double &totalPerdido,int &nro);


#endif /* FUNCIONES_H */

