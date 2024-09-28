/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PunterosGenericos.h
 * Author: aml
 *
 * Created on 22 de abril de 2024, 10:23 AM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

void cargaProductos(void *&prod);
void *leerRegProd(ifstream &arch);
char *leerCadena(ifstream &arch);
void cargaClientes(void *&cli);
void *leerRegCli(ifstream &arch);
void cargaPedidos(void *prod,void *cli);
int buscarProd(char *codigo,void **productos);
bool esProducto(char *cod,void *prod);
int buscarCli(int dni,void **clientes);
bool esCliente(int dni,void *);
void colocarPedido(void *prod,void *cli,int &nd,int cant);
void finalizarPedido(void *ped,int nd,char *codigo,int cant,double total);
void *guardaPedido(char *cod,int cant,double total);
void memoriaExacta(void *cli,int *nd);
void asignarMemExacta(void *cli,int nd);


#endif /* PUNTEROSGENERICOS_H */

