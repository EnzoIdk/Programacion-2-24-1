/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: alulab14
 *
 * Created on 5 de abril de 2024, 09:24 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void leerLibros(ifstream &archLibros,struct Libro *libros,int &numLibros);
void leerClientes(ifstream &archClientes,struct Cliente *clientes,int &numClientes);
void leerPedidos(ifstream &archPedidos,struct Libro *libros,int numLibros,
        struct Cliente *clientes,int numClientes);
int buscarCliente(struct Cliente *clientes,int numClientes,int dni);
void emitirReporte(struct Libro *libros,int numLibros,struct Cliente *clientes,
        int numClientes);
void imprimirEncabezado(ofstream &archReporte);
void imprimirLinea(ofstream &archReporte,int longitud,char simbolo);

#endif /* FUNCIONES_H */

