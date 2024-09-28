/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PunterosGenericos.h
 * Author: Enzo
 *
 * Created on 7 de mayo de 2024, 09:26 PM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

using namespace std;

void cargaproductos(void *&prod);
void *leerRegProd(ifstream &arch);
char *leerCadena(ifstream &arch,char delim);
void aumentarCap(void **&arreglo,int &nd,int &cap);
void cargapedidos(void *&ped);
void *leerRegPed(ifstream &arch);
void procesaclientes(void *prod,void *ped,void *&cli);
void colocarPedidos(void *cli,int &nd,int &cap,void *ped);
void aumentarSubCap(void *&lista,int &nd,int &cap);
void agregarPedido(void *lista,int numDat,void *pedido);
void actualizarEstados(void *prod,void *ped);
void actualizarEst(void *producto,void *pedido);
int buscarProd(void *prod,int codigo);
void *leerRegCli(ifstream &arch);

#endif /* PUNTEROSGENERICOS_H */

