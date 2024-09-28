/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: Enzo
 *
 * Created on 25 de abril de 2024, 12:53 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void leerLibros(const char *nombArch,void *&lib);
void leerRegLib(ifstream &arch,void *&reg);
char *leerCadena(ifstream &arch,char);
void imprimirLibros(void *lib);
void imprimirLibro(void *lib);
void leerClientes(const char *nombArch,void *&cli);
void leerRegCli(ifstream &arch,void *&reg);
void imprimirClientes(const char*,void *cli);
void imprimirCliente(ofstream &,void *cli);
void imprimirListaPed(ofstream &,void *listaPed,int cant);
void imprimirPed(ofstream &,void *ped);
void analizarPedidos(const char *nombArch,void *lib,void *cli);
void memoriaExacta(void *cli);
void leerDatos(ifstream &arch,int &dni,char *&pedido);
int buscarCliente(void **clientes,int dni);
bool esCliente(void *cli,int dni);
int buscarLibro(void **libros,char *codPed);
bool esLibro(void *lib,char *codPed);
void agregarPedido(void *cli,void *lib,char *codPed);
void agregarDatosALista(void *lis,int cant,char *codPed,char *titulo);
void imprimirLinea(ofstream &arch,int longitud,char simbolo);

#endif /* FUNCIONES_H */

