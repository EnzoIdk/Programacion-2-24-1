/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaConProductos.h
 * Author: Enzo
 *
 * Created on 8 de mayo de 2024, 02:02 PM
 */

#ifndef COLACONPRODUCTOS_H
#define COLACONPRODUCTOS_H

using namespace std;

void procesarPedidos(int **fechaCliCant,char **codProd,void *&prod);
void crearColaPedido(void *&cola,int *fechaCliCant);
int buscarProd(char *cod,void *prod);
void reporteDePedidos(void *productos,const char *nombArch);
void imprimirColaPedidos(ofstream &arch,void *cola);
void imprimirPedido(ofstream &arch,void *ped);

#endif /* COLACONPRODUCTOS_H */

