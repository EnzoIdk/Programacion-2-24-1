/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaConProductos.h
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 7 de mayo de 2024, 22:13
 */

#ifndef COLACONPRODUCTOS_H
#define COLACONPRODUCTOS_H

#include <fstream>
using namespace std;

void procesarPedidos(int**fecha, char**codProd, void *&prod);
int buscarProd(char*cod, void *prod);
bool compararproductos(char*cod, void*prod);
bool verificarStock(void *prod);
void crearColita(void *&prod, int *pedido);
void reporteDePedidos(void *prod, const char *nombarch);
void impresionProductos(void *prod, int ind,ofstream &arch);
void impresionRegistro(void *prod, int ind,ofstream &arch);
void impresionLista(void *cola,  ofstream &arch);
void  impresionPedido(void *prod,  ofstream &arch);
void  crearCopiaPedido(int *&pedido, int *&pedidoC);
#endif /* COLACONPRODUCTOS_H */

