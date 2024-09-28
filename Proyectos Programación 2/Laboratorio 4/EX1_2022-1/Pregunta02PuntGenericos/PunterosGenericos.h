/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PunterosGenericos.h
 * Author: Enzo
 *
 * Created on 23 de abril de 2024, 11:52 PM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

void cargaproductos(void *&prod);
void *leerRegProd(ifstream &arch);
char *leerCadena(ifstream &arch,char delim);
void cargapedidos(void *&ped);
void *leerRegPed(ifstream &arch);
void procesaclientes(void *prod,void *ped,void *&cli);
void espaciosExactosPedCli(void *cli,int nd);
void actualizarEstados(void *prod,void *ped);
void actualizarEst(void *prod,void *ped);
int buscarProd(int cod,void **productos);
bool esProducto(int cod,void *prod);
void *leerRegCli(ifstream &arch,int &dni);
void colocarPedidos(void *cli,int &numDat,int dni,void *ped);
void agregarPedido(void *cliPed,int numDat,void **pedido);
void *cargarDatosPedido(void **pedido);
void imprimereporte(void *cli);

#endif /* PUNTEROSGENERICOS_H */

