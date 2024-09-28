/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: alulab14
 *
 * Created on 19 de abril de 2024, 08:14 AM
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

void lecturaDeLibros (const char *nombArch,char ***&libros,int **&stock);
char **leerLibros(ifstream &arch);
char *leerCadena(ifstream &arch);
void leerStock(ifstream &arch,int &stock);
void aumentarCapLib(char ***&libros,int **&stock,int &nD,int &cap);
void guardarStock(int *&stock,int sto);
void pruebaDeLecturaDeLibros (const char *nombArch,char ***libros,int **stock);
void atencionDePedidos (const char *nombArch,char ***libros,int **stock, 
        int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos);
void procesarPedido(ifstream &arch,int numPed,char ***libros,int **stock,
        int *&pedCli,int &capPedCli,char **&pedLib,bool *&pedAten,int &ndPedLib,
        int &capPedLib);
int buscarLibro(char ***libros,char *codigo);
void aumentarSubCapCli(int *&pedCli,int &cap);
void aumentarSubCapPed(char **&pedLib,bool *&pedAten,int &nd,int &cap);
void leerDniNumPed(ifstream &arch,int &dni,int &numPed);
void aumentarCapCli(int **&pedCli,int &nd,int &cap);
void aumentarCapPed(char ***&pedLib,bool **&pedAten,int numPed,int &capPed);
int buscarDni(int **pedCli,int dni);
void agregarCliente(int *&pedCli,int dni);
void ordenarPedidosClientes (int **pedidosClientes);
void qSort(int **pedCli,int izq,int der);
void cambiar(int *&dato1,int *&dato2);
void reporteDeEntregaDePedidos (const char *nombArch,int **pedidosClientes,
        char ***pedidosLibros,bool **pedidosAtendidos);
void imprimirPedidos(ofstream &arch,int *pedCli,char ***pedidosLibros,
        bool **pedidosAtendidos);
void imprimirLinea(ofstream &arch,int longitud,char simbolo);

#endif /* METODOEXACTODEMEMORIA_H */

