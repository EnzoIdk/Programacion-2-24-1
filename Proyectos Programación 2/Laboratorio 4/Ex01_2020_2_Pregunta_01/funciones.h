/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: aml
 *
 * Created on 24 de abril de 2024, 09:37 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

using namespace std;

void leerDatos(void *&pedidos,void *&stock);
ifstream abrirArchL(const char *nombArch);
ofstream abrirArchE(const char *nombArch);
void leerPedidos(void *&ped,ifstream &arch);
void leerRuc(ifstream &arch,int &ruc);
void llenarBufferP(ifstream &arch,void **buffer,int &numDat,int ruc);
void *leerRegPed(ifstream &arch,int ruc);
char *leerCadena(ifstream &arch);
void leerStock(void *&sto,ifstream &arch);
void *leerRegStock(ifstream &arch);
void imprimirPed(void *ped,ofstream &arch);
void imprimirPedido(ofstream &,void*);
void imprimirSto(void *sto,ofstream &arch);
void imprimirStock(ofstream &arch,void *sto);
void atiende(void *ped,void *sto);
void ordenarPedidos(void *ped,int opcion);
void qSort(void **pedidos,int izq,int der,int opcion);
bool esMenor(void *pedI,void *pedIzq,int opcion);
void cambiar(void *&dato1,void *&dato2);
void atenderPedido(void *pedido,void *sto);
int buscarProd(int codigo,void **stock);
bool esProducto(int codigo,void *sto);
void imprimirDatos(void *ped);
void imprimirPedFinal(ofstream &arch,void *ped,int &rucBase);
void imprimirFecha(ofstream &arch,int fecha);
void imprimirLinea(ofstream &arch,int longitud,char simbolo);


#endif /* FUNCIONES_H */

