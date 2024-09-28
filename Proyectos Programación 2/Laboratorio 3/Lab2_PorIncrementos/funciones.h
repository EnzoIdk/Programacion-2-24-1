/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: alulab14
 *
 * Created on 17 de abril de 2024, 11:52 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void lecturaDeLibros (const char *nombArch,char ***&libros,int **&stock);
char **leerLibros(ifstream &arch);
char *leerCadena(ifstream &arch);
int *leerStock(ifstream &arch);
void aumentarCap(char ***&libros,int **&stock,int &numDatos,int &cap);
void pruebaDeLecturaDeLibros (const char *nombArch,char ***libros,int **stock);
void atencionDePedidos (const char *nombArch,char ***libros,int **stock,int **&pedidosClientes,
        char ***&,bool **&pedidosAtendidos);
void leerPedDNI(ifstream &arch,int &numPed,int &dni);
int buscarDNI(int **pedidosClientes,int dni,int);
void aumentarCapPedCli(int **&pedidosClientes,int &numDat,int &cap);
void aumentarCapPedLib(char ***&pedidosLibros,bool **&pedidosAtendidos,int numPed,int &cap);
void agregarCliente(int dni,int *&pedCli);
void procesarPedidos(ifstream &arch,int numPed,char ***libros,int **stock,int *&pedCli,
        int &capCli,char **&pedLib,bool *&pedAten,int &ndPed,int &capPed);
void aumentarSubCapCli(int *&pedCli,int &capCli);
void aumentarSubCapPed(char **&pedLib,bool *&pedAten,int &nd,int &cap);
int buscarLibro(char ***libros,char *codigo);
void pruebaDePedidos(const char *nombArch,int **pedidosClientes);
void reporteDeEntregaDePedidos (const char *nombArch,int **pedidosClientes,char ***,
        bool **pedidosAtendidos);
void qSort(int **pedidosClientes,int izq,int der);
void cambiar(int *&dato1,int *&dato2);
void imprimirDatosPedidos(ofstream &arch,char **pedidos,bool *atendidos);
void imprimirLinea(ofstream &arch,int longitud,char simbolo);
#endif /* FUNCIONES_H */

