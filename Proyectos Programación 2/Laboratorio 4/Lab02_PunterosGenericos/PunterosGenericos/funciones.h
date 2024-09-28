/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: aml
 *
 * Created on 24 de abril de 2024, 12:35 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void leerLibros(const char *nombArch,void *&lib);
void *leerRegLib(ifstream &arch);
char *leerCadena(ifstream &arch);
void mostrarLibros(const char *nombArch,void *lib);
void imprimirLibro(ofstream &arch,void *lib);
void atenderPedidos(const char *nombArch,void *lib,void *&pedCli,void *&pedLib);
void leerPrimerosDatos(ifstream &arch,int &numPed,int &dni);
int buscarCli(int dni,void **buffPedCli);
bool esCliente(int dni,void *pedCli);
void agregarCliente(int dni,void *&pedCli);
void registrarPedidos(ifstream &arch,void **,void *pedCli,void *&pedLib,int numPed);
void agregarPedCli(int *lista,int &nd,int numPed);


#endif /* FUNCIONES_H */

