/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: Enzo
 *
 * Created on 21 de abril de 2024, 10:43 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void leeVentas(void *&vent);
void *leerRegVenta(ifstream &arch);
char *leerCadena(ifstream &arch,char delim);
void imprimeVentas(void *vent);
void imprimeVenta(void *registro,ofstream &arch);
void leeProductos(void *&prod);
void *leerRegProd(ifstream &arch);
void imprimeProductos(void *prod);
void imprimirProducto(ofstream &arch,void *prod);
void leeClientes(void *&cli);
void *leerRegCli(ifstream &arch);
void imprimeClientes(void *cli);
void imprimeCliente(ofstream &arch,void *cli);
void liquidaVentas(void *cli,void *vent,void *prod);
void generarLiquidacion(void *&liquid,int ruc,int mes,void *vent,void *productos);
void liquidar(int ruc,int mes,void *ven,void *prod,void **buffLiq,int &numLiq);
int buscarProd(char *codProd,void **productos);
bool esProducto(char *codProd,void *prod);
void agregarVenta(char *codProd,double monto,void **buffLiq,int &numLiq);
int buscarLiq(char *cod,void **bufferLiq);
bool esLiq(char *codProd,void *liq);
void reporteLiquidacion(const char *nombArch,int ruc,void *liquid,void *prod,
        void *cli);
int buscarCliente(int ruc,void **clientes);
bool esCliente(int ruc,void *cli);
void imprimirLiquidacion(ofstream &arch,void *liq,void *prod);
void eliminaLiquidacion(void *liquidacion);
void eliminaRegLiq(void *liq);
void imprimirLinea(ofstream &arch,int longitud,char simbolo);

#endif /* FUNCIONES_H */

