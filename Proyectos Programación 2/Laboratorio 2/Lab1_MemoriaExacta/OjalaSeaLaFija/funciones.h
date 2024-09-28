/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: Enzo
 *
 * Created on 11 de abril de 2024, 04:05 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void leerLibros(const char *nombArch,char ***&libros,int *&stock,double *&precios);
char **leerDatosLibro(ifstream &arch);
char *leerCadena(ifstream &arch);
void mostrarLibros(const char *nombArch,char ***libros,int *stock,double *precios);
void imprimirDatosLibro(ofstream &archReporte,char **libros,int stock,double precio);
void leerPedidos(const char *nombArch,char ***&codPedidos,int *&codClientePed);
void espaciosExactosCodPed(char **&codPedido,char **&bufferCodPed,int nd);
void agregarCodPedidos(ifstream &arch,char **bufferCodPedidos,int &nd);
int buscarCliente(int *arreglo,int codigo);
void mostrarPedidos(const char *nombArch,char ***codigoPedidos,int *codClientePed);
void imprimirPedidos(ofstream &archReporte,char **codPedidos);

void imprimirLinea(ofstream &arch,int longitud,char simbolo);

#endif /* FUNCIONES_H */

